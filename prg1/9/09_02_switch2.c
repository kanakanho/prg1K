//
//  09_02_switch2.c
//
//
//  Created by k23060kk on 2023/06/15.
//

#include <stdio.h>

int main(int argc, const char* argv[]) {
  char ch;
  printf("text? ");

  while ((ch = getchar()) != '\n') {
    switch (ch) {
      case ' ':
        putchar('\n');
        break;
      default:
        putchar(ch);
        break;
    }
  }
  printf("\n");
  return 0;
}