//
//  11_03_dispstr1.c
//
//
//  Created by k23060kk on 2023/06/29.
//

#include <stdio.h>

int main(int argc, const char* argv[]) {
  char array[] = "abcde";
  printf("一文字ずつ印字: ");
  for (int i = 0; i < sizeof(array); i++) {
    printf("%c", array[i]);
  }
  printf("\n");
  return 0;
}
