//
//  09_01_switch1.c
//
//
//  Created by k23060kk on 2023/06/15.
//

#include <stdio.h>

int main(int argc, const char* argv[]) {
  int n;

  printf("n? ");
  scanf("%d", &n);

  switch (n) {
    case 1:
      printf("AAA\n");
      break;

    case 2:
      printf("BBB\n");
      break;

    default:
      printf("Defaultです.\n");
      break;
  }

  return 0;
}