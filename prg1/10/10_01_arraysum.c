//
//  10_01_arraysum.c
//
//
//  Created by k23060kk on 2023/06/22.
//

#include <stdio.h>

int main(int argc, const char* argv[]) {
  int evenNumbers[5] = {0};
  int sum = 0;

  for (int i = 0; i <= 5; i++) {
    evenNumbers[i] = i * 2;
    sum += evenNumbers[i];
  }

  printf("合計 = %d\n", sum);
  return 0;
}
