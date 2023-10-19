#include <stdio.h>

// プロトタイプ宣言
void swap(int *a, int *b);

int main(void) {
  // 変数の宣言
  int a = 1, b = 2;
  printf("before a = %d, b = %d\n", a, b);

  // 関数にアドレスを渡す
  swap(&a, &b);

  printf("after  a = %d, b = %d\n", a, b);
  return 0;
}

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}