#ifndef EXTRAUTIL_HH
#define EXTRAUTIL_HH

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

/*
#ifndef DEBUG
uint8_t debug = 0;
#else
uint8_t debug = 1;
#endif

#define debug_set() {debug = 1;}

#define debug_clr() {debug = 0;}

#define debug_get() {return debug}
*/

// prints error to stderr and then exits program
// prints using red color
#define eexit(...){ \
  fprintf(stderr, ANSI_COLOR_RED); \
  fprintf(stderr, __VA_ARGS__); \
  fprintf(stderr, ANSI_COLOR_RESET); \
  exit(-1); \
}

// prints to stderr using magenta color
#define warn_printf(...) { \
  fprintf(stderr, ANSI_COLOR_MAGENTA); \
  fprintf(stderr, __VA_ARGS__); \
  fprintf(stderr, ANSI_COLOR_RESET); \
}

// prints using yellow color if debug is permitted
#ifdef DEBUG
#define debug_printf(...) { \
  fprintf(stdout, ANSI_COLOR_YELLOW); \
  fprintf(stdout, __VA_ARGS__); \
  fprintf(stdout, ANSI_COLOR_RESET); \
}
#else
#define debug_printf(...) {}
#endif

// prints using blue color
#define normal_printf(...) { \
  fprintf(stdout, ANSI_COLOR_CYAN); \
  fprintf(stdout, __VA_ARGS__); \
  fprintf(stdout, ANSI_COLOR_RESET); \
}

// returns the trimmed version of this string based off delimiters
string trimmed(string orig, string delimiters);

#endif
