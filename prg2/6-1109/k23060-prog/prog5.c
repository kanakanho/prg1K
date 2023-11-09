#include <stdio.h>
#include <stdlib.h>
#define MAX 256

int main(void) {
  char line[MAX];
  FILE *fp;
  fp = fopen("meibo.txt", "r");
  if (fp == NULL) {
    printf("Cannot open the file.\n");
    exit(0);
  }
  while (fgets(line, MAX, fp) != NULL) {
    printf("%s", line);
  }
  printf("\n");
  fclose(fp);
  return 0;
}