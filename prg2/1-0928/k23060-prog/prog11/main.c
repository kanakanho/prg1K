#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  // 変数の宣言
  int minNum, maxNum, randomNum;
  while (1) {
    // 代入
    printf("min numder ? ");
    scanf("%d", &minNum);
    printf("max number ? ");
    scanf("%d", &maxNum);
    if (minNum > maxNum) {
      printf("max number is must larger than min nuber.\n");
    } else {
      break;
    }
  }
  // 乱数を生成
  srand((unsigned int)time(NULL));
  randomNum = minNum + rand() % (maxNum - minNum + 1);
  printf("%d\n", randomNum);
  return 0;
}