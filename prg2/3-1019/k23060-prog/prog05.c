#include <stdio.h>

// プロトタイプ宣言
void swap(int *a, int *b);
void sort(int *a, int *b);

int main(void) {
  // 変数の宣言
  int a = 1, b = 2;
  printf("before a = %d, b = %d\n", a, b);

  // 関数にアドレスを渡す
  sort(&a, &b);

  printf("after  a = %d, b = %d\n", a, b);
  return 0;
}

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void sort(int *a, int *b) {
  if (*a > *b) {
    swap(a, b);
  }
}