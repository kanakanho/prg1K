#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256

int prime(int n);

int main(void) {
  char line[MAX];
  FILE *fp;
  fp = fopen("prime.txt", "a");
  if (fp == NULL) {
    printf("Cannot open the file.\n");
    exit(0);
  }

  for (int i = 0; i <= 100; i++) {
    // 素数判定
    if (prime(i) == 0) {
      printf("%d\n", i);
      // ファイルに書き込み
      fprintf(fp, "%d\n", i);
    }
  }

  fclose(fp);

  return 0;
}

int prime(int n) {
  int flag = 0;
  if (n == 0 || n == 1) {
    flag = 1;
  } else {
    for (int i = 2; i < n; i++) {
      if (n % i == 0) {
        flag = 1;
        break;
      }
    }
  }
  return flag;
}