//
//  11_04_dispstr2.c
//
//
//  Created by k23060kk on 2023/06/29.
//

#include <stdio.h>

int main(int argc, const char* argv[]) {
  char inputText[11] = {'\0'};
  printf("入力(10文字以内): ");
  scanf("%s", inputText);
  for (int i = 0; i < sizeof(inputText); i++) {
    printf("%c", inputText[i]);
  }
  printf("\n");
  return 0;
}
