#include <stdio.h>

// プロトタイプ宣言
void swap(int *a, int *b);
void sort(int *a, int *b);
void sort3(int *a, int *b, int *c);

int main(void) {
  // 変数の宣言
  int a = 3, b = 2, c = 1;
  printf("before a = %d, b = %d , c = %d\n", a, b, c);

  // 関数にアドレスを渡す
  sort3(&a, &b, &c);

  printf("after  a = %d, b = %d , c = %d\n", a, b, c);
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

void sort3(int *a, int *b, int *c) {
  sort(a, b);
  sort(a, c);
  sort(b, c);
}