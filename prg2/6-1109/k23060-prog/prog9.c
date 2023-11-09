#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256

int main(void) {
  char line[MAX];
  char input[MAX] = "";
  FILE *fp;
  fp = fopen("meibo.txt", "a");
  if (fp == NULL) {
    printf("Cannot open the file.\n");
    exit(0);
  }
  do {
    printf("名前を入力してください：");
    fgets(input, MAX, stdin);
    input[strlen(input) - 1] = '\0';

    if (strcmp(input, "") != 0) {
      // 追記
      fprintf(fp, "%s\n", input);
    }
  } while (strcmp(input, "") != 0);
  printf("\n");
  fclose(fp);
  return 0;
}