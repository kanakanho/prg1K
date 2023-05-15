//
//  03_05_scan2.c
//
//
//  Created by k23060kk on 2023/04/27.
//

#include <stdio.h>

int main(int argc, const char* argv[]) {
  double a, b;                       // aとbの宣言
  printf("a b?");                    // a b?の印字
  scanf("%lf %lf", &a, &b);          // aとbに変数を入力
  printf("a = %f, b = %f\n", a, b);  // a = 5の印字
  return 0;
}
