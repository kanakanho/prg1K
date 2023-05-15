//
//  03_06_scancalc.c
//
//
//  Created by k23060kk on 2023/04/27.
//

#include <stdio.h>

int main(int argc, const char* argv[]) {
  int a, b;
  printf("a b?");
  scanf("%d %d", &a, &b);
  printf("%d + %d = %d\n", a, b, a + b);
  printf("%d - %d = %d\n", a, b, a - b);
  printf("%d * %d = %d\n", a, b, a * b);
  printf("%d / %d = %d\n", a, b, a / b);
  return 0;
}
