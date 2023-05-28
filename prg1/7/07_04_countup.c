//
//  07_04_countup.c
//
//
//  Created by k23060kk on 2023/06/1.
//

#include <stdio.h>

int main(int argc, const char* argv[]) {
  int n = 0;
  printf("n? ");
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) printf("%d\n", i);
  return 0;
}
