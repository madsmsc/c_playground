#include <stdio.h>
#include <stdlib.h>

#include "../list.h"
#include "mem.h"

struct MemNode {
  size_t size;
  void* data;
  struct MemNode* parent;
  struct ListNode* children;
};

struct MemNode* memRoot = NULL;

void mem_graph_init(void) {
  memRoot = (struct MemNode*)malloc(sizeof(struct MemNode));
  memRoot->size = 0;
  memRoot->data = NULL;
  memRoot->parent = NULL;
  memRoot->children = NULL;
}

void* mem_graph_newNode(size_t size, struct MemNode* parent) {
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

struct MemNode* mem_graph_fromPtr(void* data, struct MemNode* node) {
  if (node->data == data) {
    return node;
  }
  struct ListNode* nextChild = node->children;
  while (nextChild != NULL) {
    struct MemNode* found =
        mem_graph_fromPtr(data, (struct MemNode*)nextChild->data);
    if (found != NULL) {
      return found;
    }
    nextChild = nextChild->next;
  }
  return NULL;
}

void mem_graph_delNode(struct MemNode* node) {
  struct ListNode* child = node->children;
  while (child != NULL) {
    struct ListNode* next = child->next;
    struct MemNode* childNode = (struct MemNode*)child->data;
    mem_graph_delNode(childNode);
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

void* mem_graph_new(size_t size, void* parent) {
  struct MemNode* parentNode = memRoot;
  if (parent != NULL) {
    parentNode = mem_graph_fromPtr(parent, memRoot);
  }
  return mem_graph_newNode(size, parentNode);
}

void mem_graph_del() { mem_graph_delNode(memRoot); }

int mem_graph_print_inner(struct MemNode* node, const char* prefix) {
  size_t nodeSize = sizeof(struct MemNode) + (node->data ? node->size : 0);
  printf("%s%s %zu bytes\n", prefix, "+-", nodeSize);
  char nextPrefix[256];
  snprintf(nextPrefix, sizeof(nextPrefix), "%s%s", prefix, "|  ");
  struct ListNode* child = node->children;
  int total = (int)nodeSize;
  while (child) {
    struct MemNode* childNode = (struct MemNode*)child->data;
    total += mem_graph_print_inner(childNode, nextPrefix);
    child = child->next;
  }
  return total;
}

void mem_graph_print() {
  int total = mem_graph_print_inner(memRoot, "");
  printf("\nTotal allocated memory: %d bytes\n\n", total);
}
