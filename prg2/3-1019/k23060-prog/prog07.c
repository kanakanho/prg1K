#include <stdio.h>

int main(void) {
  int a, *pa = &a;

  printf("aのアドレス : %p\n", &a);
  printf("paのアドレス : %p\n", &pa);
  return 0;
}