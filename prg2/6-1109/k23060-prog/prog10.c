#include <stdio.h>
#include <string.h>

int main(void) {
  char str[128] = "foo,bar,hoge,fuga";
  char *elem;

  elem = strtok(str, ",");
  printf("%s\n", elem);
  while ((elem = strtok(NULL, ",")) != NULL) {
    printf("%s\n", elem);
  }

  return 0;
}