//
//  10_04_arrayswap.c
//
//
//  Created by k23060kk on 2023/06/22.
//

#include <stdio.h>

int main(int argc, const char* argv[]) {
  int a[5] = {1, 2, 3, 4, 5};
  int x, y = 0;
  int temp = 0;
  printf("何番目を入れ替えますか? ");
  scanf("%d %d", &x, &y);
  printf("%d %d\n", x, y);
  temp = a[y - 1];
  a[y - 1] = a[x - 1];
  a[x - 1] = temp;
  for (int i = 0; i < 5; i++) printf("a[%d]=%d\n", i, a[i]);

  return 0;
}
