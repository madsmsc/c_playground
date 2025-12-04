#ifndef STR_H
#define STR_H

#include <stddef.h>

char* str_random(size_t length);

void str_seedRandom(void);

void str_resetWindow(void);

void str_fun(void);

int str_len(char* str);

void str_cp(char* from, char* to);

#endif
