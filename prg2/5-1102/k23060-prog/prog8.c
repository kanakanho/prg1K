#include <stdio.h>

void swap_str_ptr(char **str1, char **str2);

int main(void) {
  char *a = "AB";
  char *b = "XY";

  printf("before\n");
  printf("a = %s\n", a);
  printf("b = %s\n", b);

  swap_str_ptr(&a, &b);

  printf("after\n");
  printf("a = %s\n", a);
  printf("b = %s\n", b);

  return 0;
}

void swap_str_ptr(char **str1, char **str2) {
  char *tmp = *str1;
  *str1 = *str2;
  *str2 = tmp;
}
