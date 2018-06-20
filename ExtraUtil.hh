#ifndef EXTRAUTIL_H_
#define EXTRAUTIL_H_

#include <stdio.h>
#include <stdlib.h>
#include <cstdarg>
#include <algorithm>
#include <string>

using namespace std;

// Allows stringification of macros
#define _MSTR(EXP) #EXP
#define MSTR(EXP) _MSTR(EXP)

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#ifndef DEBUG
uint8_t debug = 0;
#else
uint8_t debug = 1;
#endif

#define debug_set() {debug = 1;}

#define debug_clr() {debug = 0;}

#define debug_get() {return debug}

// prints error to stderr and then exits program
// prints using red color
#define eexit(fmt, ...){ \
  va_list args; \
  va_start(args, fmt); \
  fprintf(stderr, ANSI_COLOR_RED); \
  vfprintf(stderr, fmt, args); \
  fprintf(stderr, ANSI_COLOR_RESET); \
  va_end(args); \
  exit(-1); \
}

// prints to stderr using magenta color
#define warn_printf(fmt, ...) { \
  va_list args; \
  va_start(args, fmt); \
  fprintf(stderr, ANSI_COLOR_MAGENTA); \
  vfprintf(stderr, fmt, args); \
  fprintf(stderr, ANSI_COLOR_RESET); \
  va_end(args); \
}

// prints using yellow color if debug is permitted
#define debug_printf(fmt, ...) { \
  if (!debug) return; \
  va_list args; \
  va_start(args, fmt); \
  printf(ANSI_COLOR_YELLOW); \
  vprintf(fmt, args); \
  printf(ANSI_COLOR_RESET); \
  va_end(args); \
}

// prints using blue color
#define normal_printf(fmt, ...) { \
  va_list args; \
  va_start(args, fmt); \
  printf(ANSI_COLOR_CYAN); \
  vprintf(fmt, args); \
  printf(ANSI_COLOR_RESET); \
  va_end(args); \
}

// returns the trimmed version of this string based off delimiters
string trimmed(string orig, string delimiters);

#endif
