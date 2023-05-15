//
//  04_challenge1_K20000.c
//
//
//  Created by k23060kk on 2023/05/11.
//

#include <stdio.h>

int main(int argc, const char* argv[]) {
  int x, reverse = 0, i = 0;
  printf("x?");
  scanf("%d", &x);
  for (i = 0; i < 3; i++) {
    reverse = reverse * 10 + x % 10;
    x /= 10;
  }
  printf("reverse x =%d\n", reverse);
  return 0;
}
