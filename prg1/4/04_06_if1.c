//
//  04_06_if1.c
//
//
//  Created by k23060kk on 2023/05/11.
//

#include <stdio.h>

int main(int argc, const char* argv[]) {
  int a;
  printf("a?");
  scanf("%d", &a);
  if (a >= 0) {
    printf("aは正の値です\n");
  }
  return 0;
}
