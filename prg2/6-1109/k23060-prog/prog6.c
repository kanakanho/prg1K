#include <stdio.h>
#include <stdlib.h>

#define MAX 256

int main(void) {
  char line[MAX];
  FILE *fp;
  fp = fopen("number.txt", "a");
  if (fp == NULL) {
    printf("Cannot open the file.\n");
    exit(0);
  }

  for (int i = 0; i < 100; i++) {
    fprintf(fp, "%d\n", i);
  }
  return 0;
}