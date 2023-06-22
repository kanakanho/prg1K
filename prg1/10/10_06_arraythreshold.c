//
//  10_06_arraythreshold.c
//
//
//  Created by k23060kk on 2023/06/22.
//

#include <stdio.h>

int main(int argc, const char* argv[]) {
  int heights[5] = {0};
  int THRESHOLD = 170;

  for (int i = 1; i <= 5; i++) {
    printf("%d人目の身長? ", i);
    scanf("%d", &heights[i - 1]);
  }
  printf("--- しきい値を超えた人 ---\n");
  for (int i = 0; i < 5; i++)
    if (THRESHOLD <= heights[i]) printf("%d人目の身長? %d\n", i, heights[i]);
  return 0;
}
