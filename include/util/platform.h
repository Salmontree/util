#ifndef __UTIL_PLATFORM_H__
#define __UTIL_PLATFORM_H__

// Compilers
#if _ACC_
#   define COMPILER_ACC
#elif __CMB__
#   define COMPILER_CMB
#elif __CHC__
#   define COMPILER_CHC
#elif __ACK__
#   define COMPILER_ACK
#elif __CC_ARM
#   define COMPILER_ARM
#elif __AZTEC_C__
#   define COMPILER_AZTEC_C
#elif __BORLANDC__
#   define COMPILER_BORLAND
#elif __CC65__
#   define COMPILER_CC65
#elif __clang__
#   define COMPILER_CLANG
#elif __COMO__
#   define COMPILER_COMEAU
#elif __DECC
#   define COMPILER_COMPAQ
#elif __convexc__
#   define COMPILER_CONVEX
#elif __COMPCERT__
#   define COMPILER_COMPCERT
#elif __COVERITY__
#   define COMPILER_COVERITY
#elif _CRAYC
#   define COMPILER_CRAYC
#elif __DCC__
#   define COMPILER_DIAB
#elif _DICE
#   define COMPILER_DICE
#elif __DMC__
#   define COMPILER_DMC
#elif __SYSC__
#   define COMPILER_DIGNUS
#elif __DJGPP__
#   define COMPILER_DJGPP
#elif __EDG__
#   define COMPILER_EDG
#elif __GNUC__
#   define COMPILER_GCC
#elif __ghs__
#   define COMPILER_GHS
#elif __TINYC__
#   define COMPILER_TCC
#elif _MSC_VER && !__INTEL_COMPILER && !__clang__
#   define COMPILER_MSVC
#elif __MINGW32__
#   define COMPILER_MINGW
#   define COMPILER_MINGW32
#elif __MINGW64__
#   define COMPILER_MINGW
#   define COMPILER_MINGW64
#else
#   define COMPILER_UNKNOWN
#endif

// Architectures
#if __alpha__
#   define ARCH_ALPHA
#elif __amd64__ || __amd64 || __x86_64__ || __x86_64 || _M_X64 || _M_AMD64
#   define ARCH_AMD64
#   define ARCH_X86_64
#elif __arm__ || __thumb__ || _ARM || _M_ARM || __M_ARMT || __arm
#   define ARCH_ARM
#elif __aarch64__ || _M_ARM64
#   define ARCH_ARM64
#else
#   define ARCH_UNKNOWN
#endif

// Data models
#if __fourbyteints__ && __fourbyteints__ == 0
#   define DATAMODEL_LP32
#elif _ILP32 || __ILP32__ || __fourbyteints__ == 1
#   define DATAMODEL_ILP32
#elif _LP64 || __LP64__
#   define DATAMODEL_LP64
#else
#   define DATAMODEL_UNKNOWN
#endif

// Standards
#define STANDARD_UNKNOWN_ORD -1
#define STANDARD_C89_ORD 0
#define STANDARD_C94_ORD 1
#define STANDARD_C99_ORD 2
#define STANDARD_C11_ORD 3
#define STANDARD_C17_ORD 4
#define STANDARD_C23_ORD 5
#define STANDARD_CPP98_ORD 0
#define STANDARD_CPP11_ORD 1
#define STANDARD_CPP14_ORD 2
#define STANDARD_CPP17_ORD 3
#define STANDARD_CPP20_ORD 4
#define STANDARD_CPP23_ORD 5

#if (__STDC__ || COMPILER_MSVC) && !defined(__STDC_VERSION__) && !__cplusplus
#   define STANDARD_C89
#	define STANDARD_C 89
#	define STANDARD_C_ORD STANDARD_C89_ORD
#elif __STDC_VERSION__ == 199409L
#   define STANDARD_C94
#	define STANDARD_C 94
#	define STANDARD_C_ORD STANDARD_C94_ORD
#elif __STDC_VERSION__ == 199901L
#   define STANDARD_C99
#	define STANDARD_C 99
#	define STANDARD_C_ORD STANDARD_C99_ORD
#elif __STDC_VERSION__ == 201112L
#   define STANDARD_C11
#	define STANDARD_C 11
#	define STANDARD_C_ORD STANDARD_C11_ORD
#elif __STDC_VERSION__ == 201710L
#   define STANDARD_C17
#	define STANDARD_C 17
#	define STANDARD_C_ORD STANDARD_C17_ORD
#elif __STDC_VERSION__ == 202311L
#   define STANDARD_C23
#	define STANDARD_C 23
#	define STANDARD_C_ORD STANDARD_C23_ORD
#elif __cplusplus == 199711L
#   define STANDARD_CPP98
#	define STANDARD_CPP 98
#	define STANDARD_CPP_ORD STANDARD_CPP98_ORD
#elif __cplusplus == 201103L
#   define STANDARD_CPP11
#	define STANDARD_CPP 11
#	define STANDARD_CPP_ORD STANDARD_CPP11_ORD
#elif __cplusplus == 201402L
#   define STANDARD_CPP14
#	define STANDARD_CPP 14
#	define STANDARD_CPP_ORD STANDARD_CPP14_ORD
#elif __cplusplus == 201703L
#   define STANDARD_CPP17
#	define STANDARD_CPP 17
#	define STANDARD_CPP_ORD STANDARD_CPP17_ORD
#elif __cplusplus == 202002L
#   define STANDARD_CPP20
#	define STANDARD_CPP 20
#	define STANDARD_CPP_ORD STANDARD_CPP20_ORD
#elif __cplusplus == 202302L
#   define STANDARD_CPP23
#	define STANDARD_CPP 23
#	define STANDARD_CPP_ORD STANDARD_CPP23_ORD
#else
#   define STANDARD_UNKNOWN
#	define STANDARD_C UNKNOWN
#	define STANDARD_C_ORD STANDARD_UNKNOWN_ORD
#	define STANDARD_CPP UNKNOWN
#	define STANDARD_CPP_ORD STANDARD_UNKNOWN_ORD
#endif

// Languages
#if (__STDC__ || __STDC_VERSION__) && !__cplusplus
#   define LANGUAGE_C
#	define STANDARD_CPP_ORD STANDARD_UNKNOWN_ORD
#elif __cplusplus
#   define LANGUAGE_CPP
#	define STANDARD_C_ORD STANDARD_UNKNOWN_ORD
#else
#   define LANGUAGE_UNKNOWN
#	define STANDARD_C_ORD STANDARD_UNKNOWN_ORD
#	define STANDARD_CPP_ORD STANDARD_UNKNOWN_ORD
#endif

// Operating Systems
#if __ANDROID__
#   define PLATFORM_ANDROID
#   define PLATFORM_UNIX
#elif AMIGA || __amigaos__
#   define PLATFORM_AMIGA
#elif EMSCRIPTEN || __EMSCRIPTEN__
#   define PLATFORM_EMSCRIPTEN
#elif __FreeBSD__ || __FreeBSD_kernel__
#   define PLATFORM_FREEBSD
#   define PLATFORM_BSD
#   define PLATFORM_UNIX
#elif __OpenBSD__
#   define PLATFORM_OPENBSD
#   define PLATFORM_BSD
#   define PLATFORM_UNIX
#elif __NetBSD__
#   define PLATFORM_NETBSD
#   define PLATFORM_BSD
#   define PLATFORM_UNIX
#elif __APPLE__ || __MACH__ || macintosh || Macintosh
#   define PLATFORM_MACOS
#   define PLATFORM_UNIX
#elif __gnu_linux__
#   define PLATFORM_GNULINUX
#   define PLATFORM_LINUX
#   define PLATFORM_UNIX
#elif __linux__
#   define PLATFORM_LINUX
#   define PLATFORM_UNIX
#elif __unix__ || __unix
#   define PLATFORM_UNIX
#elif _WIN16 || _WIN32 || _WIN64 || __WIN32__ || __TOS_WIN__ || __WINDOWS__
#   define PLATFORM_WINDOWS
#else
#   define PLATFORM_UNKNOWN
#endif

#endif // #ifndef __UTIL_PLATFORM_H__
