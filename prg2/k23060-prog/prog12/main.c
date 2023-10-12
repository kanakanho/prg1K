#include <math.h>
#include <stdio.h>

int main(int argc, const char* argv[]) {
  int height, weight;
  double bmi;

  // 入力
  printf("身長(cm)? ");
  scanf("%d", &height);
  printf("体重(kg)? ");
  scanf("%d", &weight);

  // BMIの計算
  bmi = weight / pow(height * 0.01, 2);

  // 判定
  if (bmi < 18.5) {
    printf("やせ\n");
  } else if (bmi < 25) {
    printf("標準\n");
  } else if (bmi < 30) {
    printf("肥満\n");
  } else {
    printf("高度肥満\n");
  }
  return 0;
}
