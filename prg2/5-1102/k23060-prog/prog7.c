#include <stdio.h>

int my_strlen(char *str);
void my_strcpy(char *copy, char *original);
void swap_str(char *str1, char *str2);

int main(void) {
  char a[128] = "abcde";
  char b[128] = "xyz";

  printf("before\n");
  printf("a = %s\n", a);
  printf("b = %s\n", b);

  swap_str(a, b);

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

void my_strcpy(char *copy, char *original) {
  int i = 0;
  while (original[i] != '\0') {
    copy[i] = original[i];
    i++;
  }
  copy[i] = '\0';
}

void swap_str(char *str1, char *str2) {
  int size = my_strlen(str1);
  char tmp[size];
  my_strcpy(tmp, str1);
  my_strcpy(str1, str2);
  my_strcpy(str2, tmp);
}