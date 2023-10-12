#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  // 変数の宣言
  int randomNum;
  // シード値の変更
  srand((unsigned int)time(NULL));
  // ランダムな値を生成
  randomNum = 3 + rand() % 3;
  printf("%d\n", randomNum);
  return 0;
}