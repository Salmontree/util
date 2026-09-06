#ifndef __UTIL_TYPES_H__
#define __UTIL_TYPES_H__

#include <stddef.h>
#include <stdint.h>

// Integers
typedef int8_t   i8;
typedef int16_t  i16;
typedef int32_t  i32;
typedef int64_t  i64;
typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef u8 byte;
typedef unsigned int uint;
typedef unsigned long ulong;
typedef long long llong;
typedef long int lint;
typedef unsigned long int ulint;
typedef unsigned long long ullong;
typedef unsigned short ushort;
typedef unsigned char uchar;

// Pointer-width integers
typedef size_t usize;
typedef ptrdiff_t isize;

// Floats
typedef float  f32;
typedef double f64;

// Booleans
#ifndef LANGUAGE_CPP
#include <stdbool.h>
#endif

#endif // #ifndef __UTIL_TYPES_H__
