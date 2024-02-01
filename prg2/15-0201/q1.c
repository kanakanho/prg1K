#include <stdio.h>

int main(void) {
  char line[256];
  FILE *fp;

  // ファイルを開く
  fp = fopen("titanic.csv", "r");
  if (fp == NULL) {
    printf("ファイルを開けませんでした\n");
    return 1;
  }

  // ファイルを読み込む
  while (fgets(line, 256, fp) != NULL) {
    printf("%s", line);
  }
  return 0;
}