//
//  07_08_qq3.c
//
//
//  Created by k23060kk on 2023/06/1.
//

#include <stdio.h>

int main(int argc, const char* argv[]) {
  for (int i = 1; i <= 9; i++) {
    for (int j = 1; j <= 9; j++) {
      printf("%3d", i * j);
    }
    printf("\n");
  }
  return 0;
}
