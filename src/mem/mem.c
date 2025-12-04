#include "mem.h"

#include <stdio.h>
#include <stdlib.h>

#include "../err.h"
#include "mem_arena.h"
#include "mem_graph.h"

enum Impl impl = 0;
char* NO_IMPL_ERR = "No memory implementation chosen";

void mem_init(enum Impl chosenImpl) {
  impl = chosenImpl;
  if (impl == GRAPH) {
    mem_graph_init();
  } else if (impl == ARENA) {
    mem_arena_init();
  } else {
    err_throw("mem_init", NO_IMPL_ERR);
  }
}

void* mem_new(size_t size, void* parent) {
  if (impl == GRAPH) {
    return mem_graph_new(size, parent);
  } else if (impl == ARENA) {
    return mem_arena_new(size);
  } else {
    err_throw("mem_new", NO_IMPL_ERR);
  }
  return NULL;
}

void mem_del() {
  if (impl == GRAPH) {
    mem_graph_del();
  } else if (impl == ARENA) {
    mem_arena_del();
  } else {
    err_throw("mem_del", NO_IMPL_ERR);
  }
}

void mem_print() {
  if (impl == GRAPH) {
    mem_graph_print();
  } else if (impl == ARENA) {
    mem_arena_print();
  } else {
    err_throw("mem_print", NO_IMPL_ERR);
  }
}
