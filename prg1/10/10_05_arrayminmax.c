//
//  10_05_arrayminmax.c
//
//
//  Created by k23060kk on 2023/06/22.
//

#include <stdio.h>

int main(int argc, const char* argv[]) {
  int heights[5] = {0};
  int max, min = 0;

  for (int i = 1; i <= 5; i++) {
    printf("%d人目の身長? ", i);
    scanf("%d", &heights[i - 1]);
  }
  max = heights[0];
  min = heights[0];

  for (int i = 1; i < 5; i++) {
    if (max < heights[i]) max = heights[i];
    if (min > heights[i]) min = heights[i];
  }
  printf("最小身長は %d\n", min);
  printf("最大身長は %d\n", max);
  return 0;
}
