//
//  03_03_clac.c
//
//
//  Created by k23060kk on 2023/04/27.
//

#include <stdio.h>

int main(int argc, const char* argv[]) {
  int a, b, c, d, e;  // a,b,c,dの宣言
  a = 3;              // aに3を代入
  b = 4;              // bに4を代入
  c = 2;              // cに2を代入
  d = 8;              // dに8を代入
  e = a + b * c / d;  // 計算
  printf("%d + %d * %d / %d = %d\n", a, b, c, d, e);
  return 0;
}
