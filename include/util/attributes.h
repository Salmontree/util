#ifndef __UTIL_ATTRIBUTES_H__
#define __UTIL_ATTRIBUTES_H__

#include "platform.h"

#if defined(COMPILER_CLANG) || defined(COMPILER_GCC)
#   define ATTR_FORMAT(fmt_pos, args_pos) __attribute__((format(printf, fmt_pos, args_pos)))
#   define ATTR_UNUSED __attribute__((unused))
#   define ATTR_NON_NULL __attribute__((nonnull))
#   define ATTR_NON_NULL_ARGS(...) __attribute__((nonnull(__VA_ARGS__)))
#   define ATTR_NORETURN __attribute__((noreturn))
#   define ATTR_DEPRECATED(msg) __attribute__((deprecated(msg)))
#   define ATTR_ALWAYS_INLINE __attribute__((always_inline)) inline
#   define ATTR_NOINLINE __attribute__((noinline))
#   define ATTR_PURE __attribute__((pure))
#   define ATTR_CONST_FN __attribute__((const))
#   define ATTR_MALLOC __attribute__((malloc))
#   define ATTR_HOT __attribute__((hot))
#   define ATTR_COLD __attribute__((cold))
#   define ATTR_WARN_UNUSED_RESULT __attribute__((warn_unused_result))
#   define ATTR_PACKED __attribute__((packed))
#   define ATTR_ALIGNED(n) __attribute__((aligned(n)))
#   define ATTR_FALLTHROUGH __attribute__((fallthrough))
#   define ATTR_RESTRICT __restrict__
#elif defined(COMPILER_MSVC)
#   define ATTR_FORMAT(fmt_pos, args_pos)
#   define ATTR_UNUSED
#   define ATTR_NON_NULL
#   define ATTR_NON_NULL_ARGS(...)
#   define ATTR_NORETURN __declspec(noreturn)
#   define ATTR_DEPRECATED(msg) __declspec(deprecated(msg))
#   define ATTR_ALWAYS_INLINE __forceinline
#   define ATTR_NOINLINE __declspec(noinline)
#   define ATTR_PURE
#   define ATTR_CONST_FN
#   define ATTR_MALLOC __declspec(restrict)
#   define ATTR_HOT
#   define ATTR_COLD
#   define ATTR_WARN_UNUSED_RESULT _Check_return_
#   define ATTR_PACKED
#   define ATTR_ALIGNED(n) __declspec(align(n))
#   define ATTR_FALLTHROUGH
#   define ATTR_RESTRICT __restrict
#else
#   define ATTR_FORMAT(fmt_pos, args_pos)
#   define ATTR_UNUSED
#   define ATTR_NON_NULL
#   define ATTR_NON_NULL_ARGS(...)
#   define ATTR_NORETURN
#   define ATTR_DEPRECATED(msg)
#   define ATTR_ALWAYS_INLINE inline
#   define ATTR_NOINLINE
#   define ATTR_PURE
#   define ATTR_CONST_FN
#   define ATTR_MALLOC
#   define ATTR_HOT
#   define ATTR_COLD
#   define ATTR_WARN_UNUSED_RESULT
#   define ATTR_PACKED
#   define ATTR_ALIGNED(n)
#   define ATTR_FALLTHROUGH
#   define ATTR_RESTRICT
#endif
 
#if defined(LANGUAGE_CPP) && STANDARD_CPP_ORD >= STANDARD_CPP11_ORD
#   undef ATTR_NORETURN
#   define ATTR_NORETURN [[noreturn]]
#elif defined(LANGUAGE_C) && STANDARD_C_ORD >= STANDARD_C11_ORD
#   undef ATTR_NORETURN
#   define ATTR_NORETURN _Noreturn
#endif
 
#if defined(LANGUAGE_CPP) && STANDARD_CPP_ORD >= STANDARD_CPP17_ORD
#   undef ATTR_UNUSED
#   define ATTR_UNUSED [[maybe_unused]]
#   undef ATTR_WARN_UNUSED_RESULT
#   define ATTR_WARN_UNUSED_RESULT [[nodiscard]]
#   undef ATTR_FALLTHROUGH
#   define ATTR_FALLTHROUGH [[fallthrough]]
#elif defined(LANGUAGE_C) && STANDARD_C_ORD >= STANDARD_C23_ORD
#   undef ATTR_UNUSED
#   define ATTR_UNUSED [[maybe_unused]]
#   undef ATTR_WARN_UNUSED_RESULT
#   define ATTR_WARN_UNUSED_RESULT [[nodiscard]]
#   undef ATTR_FALLTHROUGH
#   define ATTR_FALLTHROUGH [[fallthrough]]
#endif
 
#if (defined(LANGUAGE_CPP) && STANDARD_CPP_ORD >= STANDARD_CPP14_ORD) || \
    (defined(LANGUAGE_C) && STANDARD_C_ORD >= STANDARD_C23_ORD)
#   undef ATTR_DEPRECATED
#   define ATTR_DEPRECATED(msg) [[deprecated(msg)]]
#endif
 
#if (defined(LANGUAGE_CPP) && STANDARD_CPP_ORD >= STANDARD_CPP11_ORD) || \
    (defined(LANGUAGE_C) && STANDARD_C_ORD >= STANDARD_C11_ORD)
#   undef ATTR_ALIGNED
#   define ATTR_ALIGNED(n) alignas(n)
#endif
 
#if defined(LANGUAGE_C) && STANDARD_C_ORD >= STANDARD_C99_ORD
#   undef ATTR_RESTRICT
#   define ATTR_RESTRICT restrict
#endif

#endif // #ifndef __UTIL_ATTRIBUTES_H__
