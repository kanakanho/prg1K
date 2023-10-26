#include <stdio.h>

// プロトタイプ宣言
void swap(int *px, int *py);

int main(void) {
  int x = 10, y = 5;
  printf("%d , %d\n", x, y);
  swap(&x, &y);
  printf("%d , %d\n", x, y);
  return 0;
}

void swap(int *px, int *py) {
  int tmp = *px;
  *px = *py;
  *py = tmp;
}