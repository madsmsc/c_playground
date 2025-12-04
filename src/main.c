#include "book.h"
#include "list.h"
#include "mem/mem.h"
#include "str.h"

int main(void) {
  mem_init(ARENA);
  str_resetWindow();

  list_fun();

  str_seedRandom();
  str_fun();

  void* bookPtr = book_new();
  book_print(bookPtr);

  mem_print();
  mem_del();
  mem_print();
  return 0;
}

/* TODOs
- implement unit testing
*/
