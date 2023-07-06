//
//  12_06_comparefunc.c
//
//
//  Created by k23060kk on 2023/07/06.
//

#include <stdio.h>

int maxOf(int, int);

int main(int argc, const char* argv[]) {
  int a, b;
  printf("a b? ");
  scanf("%d %d", &a, &b);
  printf("大きい方の値は %d\n", maxOf(a, b));
  return 0;
}

int maxOf(int a, int b) {
  if (a > b) {
    return a;
  } else {
    return b;
  }
}