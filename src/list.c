#include "list.h"

#include <stdint.h>
#include <stdio.h>

#include "mem/mem.h"

struct ListNode* list_new(struct ListNode* prev, void* data) {
  size_t nodeSize = sizeof(struct ListNode);
  struct ListNode* node = (struct ListNode*)mem_new(nodeSize, (void*)prev);
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
  printf("\n");
}

void list_add(struct ListNode* head, void* data) {
  struct ListNode* next = head;
  while (next->next != NULL) {
    next = next->next;
  }
  struct ListNode* newNode = list_new(next, data);
  next->next = newNode;
}

void list_fun() {
  struct ListNode* head = list_new(NULL, (void*)42);
  list_add(head, (void*)84);
  list_add(head, (void*)11);
  list_add(head, (void*)7);
  list_add(head, (void*)99);
  list_print(head);
}
