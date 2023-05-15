//
//  04_01_scan.c
//
//
//  Created by k23060kk on 2023/05/11.
//

#include <stdio.h>

int main(int argc, const char* argv[]) {
  int x;                  // xの宣言
  printf("x?");           // x?の印字
  scanf("%d", &x);        // xに入力された整数を代入
  printf("x = %d\n", x);  // x = 数字の印字
  return 0;
}
