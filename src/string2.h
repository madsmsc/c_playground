#ifndef STRING_H
#define STRING_H

#include <stddef.h>

void string_randomSet(char* str, size_t length);

char* string_random(size_t length);

void string_seedRandom(void);

void string_resetWindow(void);

void string_fun(void);

#endif
