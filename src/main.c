#include <stdio.h>

#include "book.h"
#include "list.h"
#include "mem.h"
#include "mystring.h"

int main(void) {
  mem_init();
  string_resetWindow();

  list_fun();

  string_seedRandom();
  string_fun();

  void* bookPtr = book_new();
  book_print(bookPtr);

  mem_print(memRoot);
  mem_del(memRoot->data);
  mem_print(memRoot);
  return 0;
}

/* TODOs
- encapsulate mem node graph
  implement memory arena
  enable transparent switching between the two
- remove all warnings
- book.c uses string.h for strcpy - homeroll?
- remove forward decl. of memRoot and ListNode in mem.h
*/
