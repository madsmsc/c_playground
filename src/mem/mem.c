#include "mem.h"

#include <stdio.h>
#include <stdlib.h>

#include "mem_arena.h"
#include "mem_graph.h"

enum Impl impl = 0;

void mem_init(enum Impl chosenImpl) {
  impl = chosenImpl;
  if (impl == GRAPH) {
    mem_graph_init();
  } else if (impl == ARENA) {
    mem_arena_init();
  } else {
    printf("ERROR!");
  }
}

void* mem_new(size_t size, void* parent) {
  if (impl == GRAPH) {
    return mem_graph_new(size, parent);
  } else if (impl == ARENA) {
    return mem_arena_new(size);
  } else {
    printf("ERROR!");
  }
  return NULL;
}

void mem_del() {
  if (impl == GRAPH) {
    mem_graph_del();
  } else if (impl == ARENA) {
    mem_arena_del();
  } else {
    printf("ERROR!");
  }
}

void mem_print() {
  if (impl == GRAPH) {
    mem_graph_print();
  } else if (impl == ARENA) {
    mem_arena_print();
  } else {
    printf("ERROR!");
  }
}
