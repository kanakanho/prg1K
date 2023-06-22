//
//  10_02_arrayinput.c
//
//
//  Created by k23060kk on 2023/06/22.
//

#include <stdio.h>

int main(int argc, const char* argv[]) {
  int heights[5] = {0};
  double sum = 0;
  int num = 0;

  for (int i = 1; i <= 5; i++) {
    printf("%d人目の身長? ", i);
    scanf("%d", &heights[i - 1]);
  }
  for (int i = 0; i < 5; i++) {
    sum += heights[i];
  }
  printf("平均身長 = %f\n", sum / 5);
  return 0;
}
