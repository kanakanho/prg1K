//
//  08_02_whileLoop.c
//
//
//  Created by k23060kk on 2023/06/8.
//

#include <stdio.h>

int main(int argc, const char* argv[]) {
  int n = 0;
  printf("n? ");
  scanf("%d", &n);
  for (int i = 0; i <= n; i++) {
    printf("%d\n", n - i);
  }
  return 0;
}
