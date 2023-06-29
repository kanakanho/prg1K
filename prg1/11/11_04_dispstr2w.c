//
//  11_04_dispstr2w.c
//
//
//  Created by k23060kk on 2023/06/29.
//

#include <stdio.h>

int main(int argc, const char* argv[]) {
  char inputText[11] = {'\0'};
  int index = 0;
  printf("入力(10文字以内): ");
  scanf("%s", inputText);
  // whileとputcharを使って書く
  while (index < sizeof(inputText)) {
    putchar(inputText[index]);
    index++;
  }
  printf("\n");
  return 0;
}
