#ifndef MEM_GRAPH_H
#define MEM_GRAPH_H

#include <stddef.h>

void mem_graph_init(void);

void* mem_graph_new(size_t size, void* data);

void mem_graph_del();

void mem_graph_print();

#endif
