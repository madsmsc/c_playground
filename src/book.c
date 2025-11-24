#include "book.h"

#include <stdio.h>
#include <string.h>

#include "mem.h"
#include "string2.h"

struct Book* book_new(void) {
  struct Book* bookPtr = mem_new(sizeof(struct Book), memRoot->data);
  char name[] = "bob";
  bookPtr->name = mem_new(strlen(name) + 1, bookPtr);
  strcpy(bookPtr->name, name);
  bookPtr->numberOfPages = 5;
  bookPtr->pages =
      mem_new(sizeof(struct Page) * bookPtr->numberOfPages, bookPtr);
  for (int i = 0; i < bookPtr->numberOfPages; i++) {
    bookPtr->pages[i].text = string_random(50);
    bookPtr->pages[i].number = i;
  }
  return bookPtr;
}

void book_printInfo(struct Book* bookPtr) {
  printf("Book: %s\n", bookPtr->name);
  for (int i = 0; i < bookPtr->numberOfPages; i++) {
    struct Page page = bookPtr->pages[i];
    printf("| page %d: %s\n", page.number, page.text);
  }
  printf("\n");
}
