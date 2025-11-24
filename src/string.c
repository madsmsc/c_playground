#include "string2.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "mem.h"

void string_randomSet(char* str, size_t length) {
  const char charset[] =
      "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789       ";
  size_t charsetSize = sizeof(charset) - 1;
  if (length == 0) {
    str[0] = '\0';
    return;
  }
  for (size_t i = 0; i < length; i++) {
    int key = rand() % charsetSize;
    str[i] = charset[key];
  }
  str[length] = '\0';
}

char* string_random(size_t length) {
  char* randomString = mem_new(length + 1, memRoot->data);
  string_randomSet(randomString, length);
  return randomString;
}

void string_fun() {
  char* msg = "Hello, world!";
  int charSize = sizeof(char);
  int msgLen = sizeof(msg);
  printf("msg: '%s' \ncharSize: %d \nmsgLen: %d\n", msg, charSize, msgLen);

  void* msgPtr = &msg;
  char* char5ptr = &(msg[4]);
  printf("5th char should be 'o' : %c\n", *char5ptr);
  char* char8ptr = char5ptr + (charSize * 3);
  printf("8th char should be 'w' : %c\n\n", *char8ptr);

  char* randomStr = string_random(20);
  printf("random str: %s\n\n", randomStr);
}

void string_seedRandom(void) { srand((unsigned int)time(NULL)); }

void string_resetWindow(void) { printf("\n\n\n\n\n\nWindow reset!\n\n"); }
