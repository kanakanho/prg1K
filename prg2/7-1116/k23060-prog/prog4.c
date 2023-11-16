#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char *p;
  if (((p = (char *)malloc(5 * sizeof(char))) == NULL)) {
    printf("No enough memory.\n");
    exit(1);
  }
  strcpy(p, "hoge");
  printf("%s\n", p);
  free(p);
}