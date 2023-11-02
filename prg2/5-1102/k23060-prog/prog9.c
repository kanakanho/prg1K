#include <stdio.h>
#include <string.h>

void swap_str_ptr(char **str1, char **str2);
void sort_str_ptr(char **str1, char **str2);

int main(void) {
  char *a = "abcde";
  char *b = "xyz";

  printf("before\n");
  printf("a = %s\n", a);
  printf("b = %s\n", b);

  sort_str_ptr(&a, &b);

  printf("after\n");
  printf("a = %s\n", a);
  printf("b = %s\n", b);

  return 0;
}

int my_strlen(char *str) {
  int i = 0;
  while (str[i] != '\0') {
    i++;
  }
  return i;
}

void swap_str_ptr(char **str1, char **str2) {
  char *tmp = *str1;
  *str1 = *str2;
  *str2 = tmp;
}

void sort_str_ptr(char **str1, char **str2) {
  if (strlen(*str1) > strlen(*str2)) {
    swap_str_ptr(str1, str2);
  }
}