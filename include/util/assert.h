#ifndef __UTIL_ASSERT_H__
#define __UTIL_ASSERT_H__

#include "attributes.h"
#include "types.h"

ATTR_FORMAT(5, 6) ATTR_COLD void __util_failed_assert(bool cond, const char* ATTR_RESTRICT file, const char* ATTR_RESTRICT func, usize line, const char* ATTR_RESTRICT fmt, ...);
ATTR_COLD void __util_todo(const char* ATTR_RESTRICT file, const char* ATTR_RESTRICT func, usize line);
ATTR_COLD ATTR_NORETURN void __util_unreachable(const char* ATTR_RESTRICT file, const char* ATTR_RESTRICT func, usize line);

#define ASSERT(cond, ...) __util_failed_assert((bool)(cond), __FILE__, __func__, __LINE__, __VA_ARGS__)
#define ASSERT_NULL(v, ...) ASSERT((v) == (void*)0, __VA_ARGS__)
#define ASSERT_NOT_NULL(v, ...) ASSERT((v) != (void*)0, __VA_ARGS__)
#define ASSERT_FALSE(cond, ...) ASSERT(!(cond), __VA_ARGS__)

#define TODO() __util_todo(__FILE__, __func__, __LINE__)
#define UNREACHABLE() __util_unreachable(__FILE__, __func__, __LINE__)

#endif // #ifndef __UTIL_ASSERT_H__
