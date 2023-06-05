//
//  08_challenge1_k23060.c
//
//
//  Created by k23060kk on 2023/06/8.
//

#include <stdio.h>

int main(int argc, const char* argv[]) {
  int input = 0, n = 1, i = 2;
  printf("input? ");
  scanf("%d", &input);
  while (i <= input) {
    if (input % i != 0) {
      i += 1;
      continue;
    }

    if (n) {
      printf("%d", i);
      n = 0;
    } else {
      printf(", %d", i);
    }

    input /= i;
  }
  printf("\n");
  return 0;
}
