//
//  03_07_rectangle.c
//
//
//  Created by k23060kk on 2023/04/27.
//

#include <stdio.h>

int main(int argc, const char* argv[]) {
  int a, b;
  printf("a b?");
  scanf("%d %d", &a, &b);
  printf("perimeter = %d\n", a * 2 + b * 2);
  printf("area = %d\n", a * b);
  return 0;
}
