#include "list.h"

#include <stdint.h>
#include <stdio.h>

#include "mem.h"

struct ListNode* list_newNode(struct ListNode* prev, void* data) {
  size_t nodeSize = sizeof(struct ListNode);
  void* parent = (void*)prev;
  if (parent == NULL) parent = (void*)memRoot->data;
  struct ListNode* node = (struct ListNode*)mem_new(nodeSize, parent);
  node->data = data;
  node->next = NULL;
  if (prev != NULL) prev->next = node;
  return node;
}

void list_print(struct ListNode* head) {
  struct ListNode* current = head;
  printf("List contents: ");
  while (current != NULL) {
    printf("%d -> ", (int)(intptr_t)current->data);
    current = current->next;
  }
  printf("\n\n");
}

void list_add(struct ListNode* head, void* data) {
  struct ListNode* next = head;
  while (next->next != NULL) {
    next = next->next;
  }
  struct ListNode* newNode = list_newNode(next, data);
  next->next = newNode;
}

void list_fun() {
  struct ListNode* head = list_newNode(NULL, (void*)(intptr_t)42);
  list_add(head, (void*)(intptr_t)84);
  list_add(head, (void*)(intptr_t)11);
  list_add(head, (void*)(intptr_t)7);
  list_add(head, (void*)(intptr_t)99);
  list_print(head);
}
