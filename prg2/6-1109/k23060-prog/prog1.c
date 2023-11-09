#include <stdio.h>

int main(void) {
  char* str1 = "hoge";
  char* str2 = "hage";

  if (str1 == str2)
    printf("SAME\n");
  else
    printf("DIFF\n");
  return 0;
}