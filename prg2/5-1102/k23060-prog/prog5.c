#include <stdio.h>
#include <string.h>

int main(void) {
  char a[128] = "abc";
  char b[128];

  printf("before\n");
  printf("a = %s\n", a);
  printf("b = %s\n", b);

  strcpy(b, a);

  printf("after\n");
  printf("a = %s\n", a);
  printf("b = %s\n", b);

  return 0;
}