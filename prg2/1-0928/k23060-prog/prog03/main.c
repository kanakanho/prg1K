#include <stdio.h>

int main(void) {
  // 変数の宣言
  int inputNum;
  // 数の入力
  printf("Number? ");
  scanf("%d", &inputNum);
  // 指定回数出力
  for (int i = 0; i < inputNum; i++) {
    printf("Hello, world!\n");
  }
  return 0;
}