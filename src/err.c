#include "err.h"

#include <stdio.h>
#include <stdlib.h>

char* FORMAT = "ERROR: [%s] %s";

void err_throw(char* src, char* msg) {
  printf(FORMAT, src, msg);
  exit(1);
}
