//
//  03_04_scan.c
//
//
//  Created by k23060kk on 2023/04/27.
//

#include <stdio.h>

int main(int argc, const char* argv[]) {
  int a;                  // aの宣言
  printf("a?");           // a?の印字
  scanf("%d", &a);        // aに入力された整数を代入
  printf("a = %d\n", a);  // a = 5の印字
  return 0;
}
