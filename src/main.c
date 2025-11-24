#include <stdio.h>

#include "book.h"
#include "list.h"
#include "mem.h"
#include "string2.h"

int main(void) {
  mem_init();
  string_resetWindow();

  list_fun();

  string_seedRandom();
  string_fun();

  void* bookPtr = book_new();
  book_printInfo(bookPtr);

  mem_printGraph(memRoot);
  mem_del(memRoot->data);
  mem_printGraph(memRoot);
  return 0;
}

/* TODOs
- prefer ifndef over pragma
- static before private functions in .c
*/
