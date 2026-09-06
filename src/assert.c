#include <util/assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void __util_failed_assert(const char *restrict file, const char *restrict func, usize line, const char *restrict fmt, ...) {
	printf(ANSI_COLOR_RED "Assert failed at '%s' (%s:%zu) -\n      ", file, func, line);
	
	va_list args;
	va_start(args, fmt);
	vprintf(fmt, args);
	va_end(args);

	printf(ANSI_COLOR_RESET "\n");
	exit(1);
}

void __util_todo(const char *restrict file, const char *restrict func, usize line) {
#if defined(UTIL_TODO_ERROR)
	printf(ANSI_COLOR_RED "TODO() ran at '%s' (%s:%zu)\n", file, func, line);
	exit(1);
#else
	printf(ANSI_COLOR_YELLOW "TODO() ran at '%s' (%s:%zu)\n", file, func, line);
#endif
}

void __util_unreachable(const char *restrict file, const char *restrict func, usize line) {
	printf(ANSI_COLOR_RED "UNREACHABLE() ran at '%s' (%s:%zu)\n", file, func, line);
	exit(1);
}
