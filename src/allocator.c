#include "util/allocator.h"
#include "util/attributes.h"
#include "util/assert.h"
#include "stdlib.h"

ATTR_WARN_UNUSED_RESULT ATTR_MALLOC void* c_alloc(void* state, usize size) {
	ASSERT_NULL(state, "Invalid C allocator 'alloc' call");
	ASSERT(size > 0, "Invalid C allocator 'alloc' call (size cannot be zero)");
	void* data = malloc(size);
	ASSERT_NOT_NULL(data, "Malloc call failed");
	return data;
}
ATTR_WARN_UNUSED_RESULT ATTR_MALLOC void* c_realloc(void* state, ATTR_NON_NULL void* data, usize new_size) {
	ASSERT_NULL(state, "Invalid C allocator 'realloc' call");
	ASSERT_NOT_NULL(data, "Invalid C allocator 'realloc' call (data cannot be NULL)");
	ASSERT(new_size > 0, "Invalid C allocator 'realloc' call (new_size cannot be zero)");
	void* new_data = realloc(data, new_size);
	ASSERT_NOT_NULL(new_data, "Realloc call failed");
	return new_data;
}
void c_free(void* state, ATTR_NON_NULL void* data) {
	ASSERT_NULL(state, "Invalid C allocator 'free' call");
	ASSERT_NOT_NULL(data, "Invalid C allocator 'free' call (data cannot be NULL)");
	free(data);
}
void c_freeall(ATTR_UNUSED void* state) {
	UNREACHABLE();
}
void c_destroy(ATTR_UNUSED void* state) {
	UNREACHABLE();
}
ATTR_NON_NULL ATTR_COLD alloc_t c_alloc_new(void) {
	return (alloc_t) {
		.vtable = {
			.alloc = c_alloc,
			.realloc = c_realloc,
			.free = c_free,
			.freeall = c_freeall,
			.destroy = c_destroy,
		},
		.state = NULL,
	};
}

ATTR_NON_NULL ATTR_COLD alloc_t arena_fixed_alloc_new(void) {

}

ATTR_NON_NULL ATTR_COLD alloc_t arena_growable_alloc_new(void) {

}

ATTR_NON_NULL ATTR_COLD alloc_t stack_alloc_new(void) {

}
