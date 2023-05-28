//
//  07_06_fact.c
//
//
//  Created by k23060kk on 2023/06/1.
//

#include <stdio.h>

int main(int argc, const char* argv[]) {
  int x = 0, n = 0, temp = 0;
  printf("x n? ");
  scanf("%d %d", &x, &n);
  for (int i = n; i > 0; i--) temp *= x;
  printf("%d^%d = %d\n", x, n, temp);
  return 0;
}
