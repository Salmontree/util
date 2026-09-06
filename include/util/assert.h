#ifndef __UTIL_ASSERT_H__
#define __UTIL_ASSERT_H__

#include "attributes.h"
#include "types.h"

void __util_failed_assert(const char* restrict file, const char* restrict func, usize line, const char* restrict fmt, ...)
	ATTR_FORMAT(4, 5) ATTR_COLD ATTR_NORETURN;
void __util_todo(const char* restrict file, const char* restrict func, usize line)
	ATTR_COLD;
void __util_unreachable(const char* restrict file, const char* restrict func, usize line)
	ATTR_COLD ATTR_NORETURN;

#define ASSERT(cond, ...) do { if (!(cond)) __util_failed_assert(__FILE__, __func__, __LINE__, __VA_ARGS__); } while(0)
#define ASSERT_NULL(v, ...) ASSERT((v) == (void*)0, __VA_ARGS__)
#define ASSERT_NOT_NULL(v, ...) ASSERT((v) != (void*)0, __VA_ARGS__)
#define ASSERT_FALSE(cond, ...) ASSERT(!(cond), __VA_ARGS__)

#define TODO() __util_todo(__FILE__, __func__, __LINE__)
#define UNREACHABLE() __util_unreachable(__FILE__, __func__, __LINE__)

#endif // #ifndef __UTIL_ASSERT_H__
