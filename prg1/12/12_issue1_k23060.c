//
//  12_issue1_k23060.c
//
//
//  Created by k23060kk on 2023/07/06.
//

#include <stdio.h>

int factOf(int);

int main(int argc, const char* argv[]) {
  int n;
  printf("n? ");
  scanf("%d", &n);
  printf("%dの階乗は %d\n", n, factOf(n));
  return 0;
}

int factOf(int n) {
  int tmp = 1;
  while (n > 0) {
    tmp *= n;
    n--;
  }
  return tmp;
}