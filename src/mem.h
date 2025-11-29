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

extern struct MemNode* memRoot;

void mem_init(void);

void* mem_newNode(size_t size, struct MemNode* parent);

void* mem_new(size_t size, void* data);

void mem_del(void* data);

void mem_delNode(struct MemNode* node);

struct MemNode* mem_fromPtr(void* data, struct MemNode* node);

void mem_printGraph(struct MemNode* root);

#endif
