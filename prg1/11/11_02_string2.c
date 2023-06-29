//
//  11_02_string2.c
//
//
//  Created by k23060kk on 2023/06/29.
//

#include <stdio.h>

int main(int argc, const char* argv[]) {
  char array[11] = {'\0'};
  printf("入力(10文字以内): ");
  scanf("%s", array);
  printf("%s\n", array);
  return 0;
}
