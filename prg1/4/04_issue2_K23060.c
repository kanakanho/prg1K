//
//  04_issue2_K23060.c
//
//
//  Created by k23060kk on 2023/05/11.
//

#include <stdio.h>

int main(int argc, const char* argv[]) {
  int x;
  printf("x?");
  scanf("%d", &x);
  if (x % 2 == 0) {
    printf("even\n");
  } else {
    printf("odd\n");
  }
}
