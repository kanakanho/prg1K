#include <math.h>
#include <stdio.h>

void getAvgSD(int n, int m, double *average, double *sd);

int main(void) {
  // 変数の宣言
  int num1, num2;
  double average, sd;

  // 入力
  printf("num1,num2 ? ");
  scanf("%d ,%d", &num1, &num2);

  // 関数にアドレスを渡す
  getAvgSD(num1, num2, &average, &sd);

  // 出力
  printf("avg:%f sd: %f\n", average, sd);
  return 0;
}

void getAvgSD(int num1, int num2, double *paverage, double *psd) {
  *paverage = (double)(num1 + num2) / 2;
  double variance;
  variance = (pow((num1 - *paverage), 2.0) + pow((num2 - *paverage), 2.0)) / 2;
  *psd = sqrt(variance);
}