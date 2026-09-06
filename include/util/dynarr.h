#ifndef __UTIL_DYNARR_H__
#define __UTIL_DYNARR_H__

#include "util/attributes.h"
#include "util/types.h"
#include "util/assert.h" // IWYU pragma: keep
#include <stdio.h> // IWYU pragma: keep

#define ARRLEN(arr) (sizeof(arr) / sizeof(*(arr)))

typedef struct {
	usize len, cap;
	usize elem_size;
} dynarr_header_t;

union __util_dynarr_align_u {
	dynarr_header_t __align_header;
	void* __align_ptr;
	double __align_dbl;
	long __align_lng;
};
#define __UTIL_DYNARR_HEADER_SIZE sizeof(union __util_dynarr_align_u)

#define __UTIL_DYNARR_HEADER(v) ((dynarr_header_t*)((char*)(v) - __UTIL_DYNARR_HEADER_SIZE))
#define __UTIL_DYNARR_INITIAL_CAP ((usize)4)

ATTR_MALLOC ATTR_WARN_UNUSED_RESULT void* __util_dynarr_new(usize elem_size);
ATTR_NON_NULL void  __util_dynarr_free_ip(void** arr_ptr);
ATTR_NON_NULL int   __util_dynarr_reserve_ip(void** arr_ptr, usize min_cap);
ATTR_NON_NULL ATTR_WARN_UNUSED_RESULT int __util_dynarr_shrink_to_fit_ip(void** arr_ptr);
ATTR_NON_NULL void  __util_dynarr_make_room(void* arr, usize i);
ATTR_NON_NULL void  __util_dynarr_remove_ordered(void* arr, usize i);
ATTR_NON_NULL void  __util_dynarr_remove_unordered(void* arr, usize i);
ATTR_NON_NULL usize __util_dynarr_index_of(const void* arr, const void* elem);

#define DYNARR(t) t*

#define DYNARR_NEW(t) ((DYNARR(t))__util_dynarr_new(sizeof(t)))
#define DYNARR_FREE(v) __util_dynarr_free_ip((void**)&(v))
#define DYNARR_CLEAR(v) (__UTIL_DYNARR_HEADER(v)->len = 0)
#define DYNARR_AT(v, i) ( ASSERT((usize)(i) < __UTIL_DYNARR_HEADER(v)->len, "Dynamic Array access out-of-bounds: index %zu, len %zu", (usize)(i), __UTIL_DYNARR_HEADER(v)->len), (v)[i] )
#define DYNARR_PUSH(v, elem) \
	( __util_dynarr_reserve_ip((void**)&(v), __UTIL_DYNARR_HEADER(v)->len + 1) \
		? ((v)[__UTIL_DYNARR_HEADER(v)->len++] = (elem), 1) : 0 )
#define DYNARR_POP(v) ( ASSERT(__UTIL_DYNARR_HEADER(v)->len > 0, "Dynamic Array popping empty DYNARR"), (v)[--__UTIL_DYNARR_HEADER(v)->len] )
#define DYNARR_INSERT(v, i, elem) \
	( __util_dynarr_reserve_ip((void**)&(v), __UTIL_DYNARR_HEADER(v)->len + 1) \
		? (__util_dynarr_make_room((v), (usize)(i)), (v)[i] = (elem), 1) : 0 )
#define DYNARR_REMOVE_ORDERED(v, i) __util_dynarr_remove_ordered((v), (usize)(i))
#define DYNARR_REMOVE_UNORDERED(v, i) __util_dynarr_remove_unordered((v), (usize)(i))
#define DYNARR_INDEX_OF(v, elem_var) __util_dynarr_index_of((v), &(elem_var))
#define DYNARR_CONTAINS(v, elem_var) (DYNARR_INDEX_OF((v), (elem_var)) != (usize)-1)
#define DYNARR_LEN(v) (__UTIL_DYNARR_HEADER(v)->len)
#define DYNARR_CAP(v) (__UTIL_DYNARR_HEADER(v)->cap)
#define DYNARR_EMPTY(v) (DYNARR_LEN(v) == 0)
#define DYNARR_LAST(v) ( ASSERT(!DYNARR_EMPTY(v), "Dynamic Array cannot get element of empty DYNARR"), (v)[DYNARR_LEN(v) - 1] )
#define DYNARR_RESERVE(v, n) __util_dynarr_reserve_ip((void**)&(v), (usize)(n))
#define DYNARR_SHRINK_TO_FIT(v) __util_dynarr_shrink_to_fit_ip((void**)&(v))

#endif // #ifndef __UTIL_DYNARR_H__
