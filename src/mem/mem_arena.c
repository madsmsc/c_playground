#include "mem_arena.h"

#include <stdio.h>
#include <stdlib.h>

struct MemArena {
  size_t ownSize;
  void* start;
  void* current;
};

size_t ARENA_SIZE = 10000;

struct MemArena* arena = NULL;

void mem_arena_init(void) {
  int ownSize = sizeof(struct MemArena);
  arena = (struct MemArena*)malloc(ownSize);
  arena->ownSize = ownSize;
  arena->start = malloc(ARENA_SIZE);
  arena->current = arena->start;
}

size_t usedSize() {
  size_t from = (size_t)arena->start;
  size_t to = (size_t)arena->current;
  return to - from;
}

void* mem_arena_new(size_t size) {
  void* ret = arena->current;
  arena->current += size;
  if (usedSize() > ARENA_SIZE) {
    printf("ERROR: Not enough room in arena\n");
    arena->current = ret;
    return NULL;
  }
  return ret;
}

void mem_arena_del() {
  arena->current = arena->start;
  printf("Reset arena current pointer to start\n\n");
}

void mem_arena_print() {
  printf("Allocated %d bytes\n", (int)ARENA_SIZE);
  printf("And %d bytes for the arena metadata\n", (int)arena->ownSize);
  printf("Used %llu bytes of arena\n\n", usedSize());
}
