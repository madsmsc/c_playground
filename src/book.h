#ifndef BOOK_H
#define BOOK_H

struct Page {
  char* text;
  int number;
};

struct Book {
  int numberOfPages;
  struct Page* pages;
  char* name;
};

struct Book* book_new(void);

void book_printInfo(struct Book* bookPtr);

#endif
