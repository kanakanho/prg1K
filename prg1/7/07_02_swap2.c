//
//  07_02_swap2.c
//
//
//  Created by k23060kk on 2023/06/1.
//

#include <stdio.h>

int main(int argc, const char* argv[]) {
  // x, y, tempの宣言
  int x = 0, y = 0, temp = 0;
  // x, yの入力
  printf("x y? ");
  scanf("%d %d", &x, &y);
  if (x < y)
    // xとyの値を印字
    printf("%d %d\n", x, y);
  else {
    // xとyの値を交換
    temp = x;
    x = y;
    y = temp;
    // xとyの値を印字
    printf("%d %d\n", x, y);
  }
  return 0;
}
