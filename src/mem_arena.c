#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "mem.h"
/* find some other way to switch between implementations

struct MemNode* memRoot = NULL;
// have a ptr instead? or can this be re-used for both impls?

void mem_init(void) {
  // allocate big chunk
}

void* mem_new(size_t size, void* data) {
  // move ptr.
}

void mem_del(void* data) {
  // not implemented - should free up ptr or remove whole arena?
}

void mem_print(struct MemNode* root) { printf("arena under construction"); }
*/
