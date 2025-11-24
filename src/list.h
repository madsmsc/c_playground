#ifndef LIST_H
#define LIST_H

struct ListNode {
  void* data;
  struct ListNode* next;
};

struct ListNode* list_newNode(struct ListNode* prev, void* data);

void list_add(struct ListNode* head, void* data);

void list_print(struct ListNode* head);

void list_fun(void);

#endif
