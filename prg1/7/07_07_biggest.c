//
//  07_07_biggest.c
//
//
//  Created by k23060kk on 2023/06/1.
//

#include <stdio.h>

int main(int argc, const char* argv[]) {
  int x = 0, i = 0, max = 0;
  for (int i = 1; i <= 5; i++) {
    printf("%d? ", i);
    scanf("%d", &x);
    if (x > max) max = x;
  }
  scanf("max = %d\n", &x);
  return 0;
}
