//
//  12_05_compare.c
//
//
//  Created by k23060kk on 2023/07/06.
//

#include <stdio.h>

int main(int argc, const char* argv[]) {
  int a, b;
  printf("a b? ");
  scanf("%d %d", &a, &b);
  printf("大きい方の値は ");
  if (a > b) {
    printf("%d\n", a);
  } else {
    printf("%d\n", b);
  }
  return 0;
}
