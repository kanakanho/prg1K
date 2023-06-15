//
//  09_challenge1_k23060.c
//
//
//  Created by k23060kk on 2023/06/15.
//

#include <stdio.h>

int main(int argc, const char* argv[]) {
  char ch = ' ';
  int isPlus = 1;
  int sum = 0;
  int n;

  printf("equation? ");
  while (ch != '=') {
    ch = getchar();

    switch (ch) {
      case ' ':
      case '=':
      case '\n':
      case '\t':
        break;

      case '+':
        isPlus = 1;
        break;

      case '-':
        isPlus = 0;
        break;

      default:
        n = (int)ch - 48;
        sum += isPlus ? n : -n;

        break;
    }
  }
  printf("answer: %d\n", sum);

  return 0;
}
