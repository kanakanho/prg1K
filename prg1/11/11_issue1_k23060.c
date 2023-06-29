//
//  11_issue1_k23060.c
//
//
//  Created by k23060kk on 2023/06/29.
//

#include <stdio.h>

int main(int argc, const char* argv[]) {
  char inputText[21] = {'\0'};
  int isPalindrome = 0;
  int textLength = 0;
  // 入力
  printf("input(20文字以下): ");
  scanf("%s", inputText);
  // 文字数を取得
  for (int i = 0; i < 21; i++) {
    if (inputText[i] == '\0') {
      textLength = i;
      break;
    }
  }
  // 回文かどうか判定
  for (int i = 0; i < textLength / 2; i++) {
    if (inputText[i] != inputText[textLength - i - 1]) {
      isPalindrome = 1;
      break;
    }
  }
  // 出力
  printf("%s\n", isPalindrome ? "回文NG" : "回文OK");
  return 0;
}