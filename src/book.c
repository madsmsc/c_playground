#include "book.h"

#include <stdio.h>

#include "mem/mem.h"
#include "str.h"

struct Book* book_new(void) {
  struct Book* bookPtr = mem_new(sizeof(struct Book), NULL);
  char* name = "bob";
  int nameLen = str_len(name);
  bookPtr->name = mem_new(nameLen, bookPtr);
  str_cp(bookPtr->name, name);
  bookPtr->numberOfPages = 5;
  bookPtr->pages =
      mem_new(sizeof(struct Page) * bookPtr->numberOfPages, bookPtr);
  for (int i = 0; i < bookPtr->numberOfPages; i++) {
    bookPtr->pages[i].text = str_random(50);
    bookPtr->pages[i].number = i;
  }
  return bookPtr;
}

void book_print(struct Book* bookPtr) {
  printf("Book: %s\n", bookPtr->name);
  for (int i = 0; i < bookPtr->numberOfPages; i++) {
    struct Page page = bookPtr->pages[i];
    printf("| page %d: %s\n", page.number + 1, page.text);
  }
  printf("\n");
}
