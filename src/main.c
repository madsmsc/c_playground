#include <stdio.h>

#include "book.h"
#include "list.h"
#include "mem/mem.h"
#include "mystring.h"

int main(void) {
  mem_init(ARENA);
  string_resetWindow();

  list_fun();

  string_seedRandom();
  string_fun();

  void* bookPtr = book_new();
  book_print(bookPtr);

  mem_print();
  mem_del();
  mem_print();
  return 0;
}

/* TODOs
- book.c uses string.h for strcpy - homeroll?
- size_t == long long unsigned
*/
