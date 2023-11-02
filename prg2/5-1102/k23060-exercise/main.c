#include <stdio.h>

int my_strlen(char *str);
void swap_str_ptr(char **str1, char **str2);
void sort_str_ptr(char **str1, char **str2);
void bubble_str_ptr(char **str, int size);

int main(void) {
  char *list[] = {"hoge", "abc", "xy", "fugagaga"};

  printf("--------------------\n");
  printf("before\n");
  printf("--------------------\n");
  for (int i = 0; i < 4; i++) {
    printf("%d : %s\n", i, list[i]);
  }

  bubble_str_ptr(list, 4);

  printf("--------------------\n");
  printf("after\n");
  printf("--------------------\n");
  for (int i = 0; i < 4; i++) {
    printf("%d : %s\n", i, list[i]);
  }
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
  int size1 = my_strlen(*str1);
  int size2 = my_strlen(*str2);
  if (size1 > size2) {
    swap_str_ptr(str1, str2);
  }
}

void bubble_str_ptr(char **str, int size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - 1 - i; j++) {
      sort_str_ptr(&str[j], &str[j + 1]);
    }
  }
}