#include <stdio.h>

void getSumDiff(int num1, int num2, int *psum, int *pdiff) {
  // ポインタを用いて値を変更する
  *psum = num1 + num2;
  *pdiff = num1 - num2;
}

int main(void) {
  // 変数の宣言
  int num1 = 10, num2 = 5, sum = 0, diff = 0;

  // num1,num2は値を渡す、sum,diffはアドレスを渡す
  getSumDiff(num1, num2, &sum, &diff);

  printf("%d, %d\n", sum, diff);
  return 0;
}