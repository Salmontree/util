#include <stdlib.h>
#include <string.h>
#include <util/dynarr.h>

ATTR_WARN_UNUSED_RESULT ATTR_MALLOC void* __util_dynarr_new(usize elem_size) {
	dynarr_header_t* header = (dynarr_header_t*)malloc(__UTIL_DYNARR_HEADER_SIZE + __UTIL_DYNARR_INITIAL_CAP * elem_size);
	if (header == NULL) return NULL;

	header->len = 0; header->cap = __UTIL_DYNARR_INITIAL_CAP;
	header->elem_size = elem_size;

	return (void*)((char*)header + __UTIL_DYNARR_HEADER_SIZE);
}

ATTR_NON_NULL void __util_dynarr_free_ip(void** arr_ptr) {
	if (*arr_ptr == NULL) return;
	free((void*)__UTIL_DYNARR_HEADER(*arr_ptr));
	*arr_ptr = NULL;
}

ATTR_NON_NULL int __util_dynarr_reserve_ip(void** arr_ptr, usize min_cap) {
	dynarr_header_t* header = __UTIL_DYNARR_HEADER(*arr_ptr);
	dynarr_header_t* new_header;
	usize new_cap;
 
	if (min_cap <= header->cap) return 1;
 
	new_cap = header->cap != 0 ? header->cap : 1;
	while (new_cap < min_cap) new_cap *= 2;
 
	new_header = (dynarr_header_t*)realloc((void*)header, __UTIL_DYNARR_HEADER_SIZE + new_cap * header->elem_size);
	if (new_header == NULL) return 0;
 
	new_header->cap = new_cap;
	*arr_ptr = (void*)((char*)new_header + __UTIL_DYNARR_HEADER_SIZE);
	return 1;
}

ATTR_NON_NULL ATTR_WARN_UNUSED_RESULT int __util_dynarr_shrink_to_fit_ip(void** arr_ptr) {
	dynarr_header_t* header = __UTIL_DYNARR_HEADER(*arr_ptr);
	dynarr_header_t* new_header;

	if (header->len == header->cap) {
		return 1;
	}

	new_header = (dynarr_header_t*)realloc((void*)header, __UTIL_DYNARR_HEADER_SIZE + header->len * header->elem_size);
	if (new_header == NULL) return 0;

	new_header->cap = new_header->len;
	*arr_ptr = (void*)((char*)new_header + __UTIL_DYNARR_HEADER_SIZE);
	return 1;
}

ATTR_NON_NULL void __util_dynarr_make_room(void* arr, usize i) {
	dynarr_header_t* header = __UTIL_DYNARR_HEADER(arr);
	ASSERT(i <= header->len, "Dynamic Array index out-of-bounds: index: %zu, len: %zu", i, header->len);
	if (i < header->len) memmove(arr + (i + 1) * header->elem_size, arr + i * header->elem_size, (header->len - i) * header->elem_size);
	header->len += 1;
}

ATTR_NON_NULL void __util_dynarr_remove_ordered(void* arr, usize i) {
	dynarr_header_t* header = __UTIL_DYNARR_HEADER(arr);
	ASSERT(i < header->len, "Dynamic Array access out-of-bounds: index: %zu, len: %zu", i, header->len);
	if (i + 1 < header->len) memmove(arr + i * header->elem_size, arr + (i+1) * header->elem_size, (header->len - i - 1) * header->elem_size);
	header->len -= 1;
}

ATTR_NON_NULL void __util_dynarr_remove_unordered(void* arr, usize i) {
	dynarr_header_t* header = __UTIL_DYNARR_HEADER(arr);
	ASSERT(i < header->len, "Dynamic Array access out-of-bounds: index: %zu, len: %zu", i, header->len);
	if (i != header->len - 1) memcpy(arr + i * header->elem_size, arr + (header->len-1) * header->elem_size, header->elem_size);
	header->len -= 1;
}

ATTR_NON_NULL usize __util_dynarr_index_of(const void* arr, const void* elem) {
	const dynarr_header_t* header = (const dynarr_header_t*)((const char*)arr - __UTIL_DYNARR_HEADER_SIZE);

	usize i;
	for (i = 0; i < header->len; i++)
		if (memcmp(arr + i * header->elem_size, elem, header->elem_size) == 0)
			return i;
	return (usize)-1;
}
