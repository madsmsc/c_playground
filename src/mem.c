#include "mem.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

struct MemNode* memRoot = NULL;

void mem_init(void) {
  memRoot = (struct MemNode*)malloc(sizeof(struct MemNode));
  memRoot->size = 0;
  memRoot->data = NULL;
  memRoot->parent = NULL;
  memRoot->children = NULL;
}

void* mem_newNode(size_t size, struct MemNode* parent) {
  struct MemNode* node = (struct MemNode*)malloc(sizeof(struct MemNode));
  node->size = size;
  node->data = malloc(size);
  node->parent = parent;
  node->children = NULL;
  if (parent != NULL) {
    struct ListNode* child = (struct ListNode*)malloc(sizeof(struct ListNode));
    child->data = node;
    child->next = NULL;
    if (parent->children == NULL) {  // no children, add first
      parent->children = child;
    } else {  // add to end of children
      struct ListNode* nextChild = parent->children;
      while (nextChild->next != NULL) {
        nextChild = nextChild->next;
      }
      nextChild->next = child;
    }
  }
  return node->data;
}

struct MemNode* mem_fromPtr(void* data, struct MemNode* node) {
  if (node->data == data) {
    return node;
  }
  struct ListNode* nextChild = node->children;
  while (nextChild != NULL) {
    struct MemNode* found = mem_fromPtr(data, (struct MemNode*)nextChild->data);
    if (found != NULL) {
      return found;
    }
    nextChild = nextChild->next;
  }
  return NULL;
}

void mem_delNode(struct MemNode* node) {
  struct ListNode* child = node->children;
  while (child != NULL) {
    struct ListNode* next = child->next;
    struct MemNode* childNode = (struct MemNode*)child->data;
    mem_delNode(childNode);
    free(child);
    child = next;
  }
  node->children = NULL;
  if (node->data != NULL) {  // never free memRoot
    free(node->data);
    node->data = NULL;
    free(node);
  }
}

void* mem_new(size_t size, void* data) {
  struct MemNode* node = mem_fromPtr(data, memRoot);
  return mem_newNode(size, node);
}

void mem_del(void* data) {
  struct MemNode* node = mem_fromPtr(data, memRoot);
  mem_delNode(node);
}

int mem_printGraph_inner(struct MemNode* node, const char* prefix) {
  size_t nodeSize = sizeof(struct MemNode) + (node->data ? node->size : 0);
  printf("%s%s %zu bytes\n", prefix, "+-", nodeSize);
  char nextPrefix[256];
  snprintf(nextPrefix, sizeof(nextPrefix), "%s%s", prefix, "|  ");
  struct ListNode* child = node->children;
  int total = (int)nodeSize;
  while (child) {
    struct MemNode* childNode = (struct MemNode*)child->data;
    total += mem_printGraph_inner(childNode, nextPrefix);
    child = child->next;
  }
  return total;
}

void mem_printGraph(struct MemNode* root) {
  int total = mem_printGraph_inner(root, "");
  printf("\nTotal allocated memory: %d bytes\n\n", total);
}
