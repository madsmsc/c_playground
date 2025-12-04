#ifndef MEM_ARENA_H
#define MEM_ARENA_H

#include <stddef.h>

void mem_arena_init(void);

void* mem_arena_new(size_t size);

void mem_arena_del();

void mem_arena_print();

#endif
