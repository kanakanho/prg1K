#include <stdio.h>

// プロトタイプ宣言
void swap(int x, int y);

int main(void) {
  int x = 10, y = 5;
  printf("%d , %d\n", x, y);
  swap(&x, &y);
  printf("%d , %d\n", x, y);
  return 0;
}

void swap(int x, int y) {
  int tmp = x;
  x = y;
  y = tmp;
}