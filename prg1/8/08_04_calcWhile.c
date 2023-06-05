//
//  08_04_calcWhile.c
//
//
//  Created by k23060kk on 2023/06/8.
//

#include <stdio.h>

int main(int argc, const char* argv[]) {
  int x, sum;
  sum = 0;
  while (x != 0) {
    printf("x? ");
    scanf("%d", &x);
    sum += x;
    printf("sum: %d\n", sum);
  }
  printf("end\n");
  return 0;
}
