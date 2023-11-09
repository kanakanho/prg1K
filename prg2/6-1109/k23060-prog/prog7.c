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

  for (int i = 100; i < 200; i++) {
    fprintf(fp, "%d\n", i);
  }

  fclose(fp);
  return 0;
}