//
//  03_issue1_K23060.c
//
//
//  Created by k23060kk on 2023/04/27.
//

#include <stdio.h>

int main(int argc, const char* argv[]) {
  int a, b, c, d;                               // aとbとcとdの宣言
  a = 6;                                        // aに6を代入
  b = 4;                                        // bに4を代入
  c = 2;                                        // cに2を代入
  d = a - (b / c);                              // dにa - (b / c)を代入
  printf("%d - (%d / %d) = %d\n", a, b, c, d);  // 6 - (4 / 2) = 4を印字
  return 0;
}
