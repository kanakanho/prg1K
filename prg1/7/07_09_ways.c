//
//  07_09_ways.c
//
//
//  Created by k23060kk on 2023/06/1.
//

#include <stdio.h>

int main(int argc, const char* argv[]) {
  int n = 0, x = 0, count = 0;
  printf("n x? ");
  scanf("%d %d", &n, &x);
  for (int i = n - 2; i <= n; i++) {
    for (int j = n - 2; j <= n; j++) {
      for (int k = n - 2; k <= n; k++) {
        if (i + j + k == x) {
          printf("%d%d%d\n", i, j, k);
          count += 1;
        }
      }
    }
  }
  printf("組み合わせの数: %d\n", count);
  return 0;
}
