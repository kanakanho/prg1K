#include <stdio.h>

int main(void) {
  int i;
  char a[][5] = {"LISP", "C", "Ada"};
  char *p[] = {"PAUL", "X", "MAC"};
  int size;

  size = sizeof(a) / sizeof(a[0]);
  for (i = 0; i < size; i++) printf("a[%d] = \"%s\"\n", i, a[i]);
  size = sizeof(p) / sizeof(p[0]);
  for (i = 0; i < size; i++) printf("p[%d] = \"%s\"\n", i, p[i]);

  return 0;
}