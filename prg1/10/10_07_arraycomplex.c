//
//  10_07_arraycomplex.c
//
//
//  Created by k23060kk on 2023/06/22.
//

#include <math.h>
#include <stdio.h>

int main(int argc, const char* argv[]) {
  int heights[5] = {0};
  int weights[5] = {0};
  int THRESHOLD = 23;
  double standardWeight;
  double bmi;

  // 入力
  for (int i = 1; i <= 5; i++) {
    printf("%d人目の身長と体重? ", i);
    scanf("%d %d", &heights[i - 1], &weights[i - 1]);
  }

  // 判定
  for (int i = 0; i < 5; i++) {
    // BMIの計算
    bmi = weights[i] / pow(heights[i] * 0.01, 2);
    if (bmi > 23) {
      // 標準体重の計算
      standardWeight = (heights[i] - 100) * 0.9;
      printf("%d人目のBMI: %f, 標準体重との差: %f\n", i, bmi,
             weights[i] - standardWeight);
    }
  }
}
