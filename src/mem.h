#ifndef MEM_H
#define MEM_H

#include <stddef.h>

struct ListNode;  // forward - necessary?

struct MemNode {
  size_t size;
  void* data;
  struct MemNode* parent;
  struct ListNode* children;
};

extern struct MemNode* memRoot; // can I avoid this?
// essentially let mem.c have a reference to something
// new'd in main?

void mem_init(void);

void* mem_new(size_t size, void* data);

void mem_del(void* data);

void mem_print(struct MemNode* root);

#endif
