//
//  03_issue2_K23060.c
//
//
//  Created by k23060kk on 2023/04/27.
//

#include <stdio.h>

int main(int argc, const char* argv[]) {
  int x, y;
  printf("x?");
  scanf("%d", &x);
  y = x * x;
  printf("%d の二乗は %d です\n", x, y);
  return 0;
}
