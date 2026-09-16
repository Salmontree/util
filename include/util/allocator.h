#ifndef __UTIL_ALLOCATOR_H__
#define __UTIL_ALLOCATOR_H__

#include "util/attributes.h"
#include "util/types.h"

typedef struct {
	struct {
		ATTR_WARN_UNUSED_RESULT void* (*alloc)(void* state, usize size);
		ATTR_WARN_UNUSED_RESULT void* (*realloc)(void* state, void* data, usize new_size);
		void  (*free)(void* state, void* data);
		void  (*freeall)(void* state);
		void  (*destroy)(void* state);
	} vtable;
	void* state;
} alloc_t;

#define ALLOC(allocator, size) (allocator).vtable.alloc((allocator).state, (size))
#define ALLOC_NEW(allocator, type) ALLOC((allocator), sizeof(type))
#define ALLOC_ARRAY(allocator, type, len) ALLOC((allocator), sizeof(type) * (len))
#define ALLOC_REALLOC(allocator, data, new_len) (allocator).vtable.realloc((allocator).state, (data), (new_len))
#define ALLOC_FREE(allocator, data) (allocator).vtable.free((allocator).state, (data))
#define ALLOC_FREEALL(allocator) (allocator).vtable.freeall((allocator).state)
#define ALLOC_DESTROY(allocator) (allocator).vtable.destroy((allocator).state)

ATTR_WARN_UNUSED_RESULT ATTR_NON_NULL ATTR_COLD alloc_t c_alloc_new(void);
ATTR_WARN_UNUSED_RESULT ATTR_NON_NULL ATTR_COLD alloc_t arena_fixed_alloc_new(void);
ATTR_WARN_UNUSED_RESULT ATTR_NON_NULL ATTR_COLD alloc_t arena_growable_alloc_new(void);
ATTR_WARN_UNUSED_RESULT ATTR_NON_NULL ATTR_COLD alloc_t stack_alloc_new(void);

#endif // #ifndef __UTIL_ALLOCATOR_H__
