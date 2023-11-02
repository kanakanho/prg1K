#include <stdio.h>
#include <string.h>

int main(void) {
  char *str = "abcd";
  int size;

  size = strlen(str);
  for (int i = 0; i < size; i++) printf("%c\n", str[i]);

  return 0;
}