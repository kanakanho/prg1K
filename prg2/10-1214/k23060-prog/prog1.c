#include <stdio.h>
#define MES

int main(void) {
#ifdef MES
  printf("Debug message\n");
#endif
  return 0;
}