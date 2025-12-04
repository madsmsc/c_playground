#ifndef MEM_H
#define MEM_H

#include <stddef.h>

enum Impl { ARENA, GRAPH };

void mem_init(enum Impl impl);

void* mem_new(size_t size, void* data);

void mem_del();

void mem_print();

#endif
