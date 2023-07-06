//
//  12_08_sumfunc.c
//
//
//  Created by k23060kk on 2023/07/06.
//

#include <stdio.h>

int sumOf(int);

int main(int argc, const char* argv[]) {
  int n;
  printf("n? ");
  scanf("%d", &n);
  printf("1から%dまでの和は %d\n", n, sumOf(n));
  return 0;
}

int sumOf(int n) {
  int tmp = 0;
  for (int i = 1; i <= n; i++) {
    tmp += i;
  }
  return tmp;
}