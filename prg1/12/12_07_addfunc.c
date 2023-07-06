//
//  12_06_comparefunc.c
//
//
//  Created by k23060kk on 2023/07/06.
//

#include <stdio.h>

int addOf(int, int);

int main(int argc, const char* argv[]) {
  int a, b;
  printf("a b? ");
  scanf("%d %d", &a, &b);
  printf("和は %d\n", addOf(a, b));
  return 0;
}

int addOf(int a, int b) { return a + b; }