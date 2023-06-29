//
//  11_05_scan_rev.c
//
//
//  Created by k23060kk on 2023/06/29.
//

#include <stdio.h>

int main(int argc, const char* argv[]) {
  char inputText[6] = {'\0'};
  printf("input: ");
  scanf("%s", inputText);
  for (int i = sizeof(inputText); i >= 0; i--) {
    printf("%c", inputText[i]);
  }
  printf("\n");
  return 0;
}
