//
//  04_issue1_K23060.c
//
//
//  Created by k23060kk on 2023/05/11.
//

#include <stdio.h>

int main(int argc, const char* argv[]) {
  int hight_cm, weight;
  double standardWeight, hight_m, bmi;
  printf("hight?");
  scanf("%d", &hight_cm);
  printf("weight?");
  scanf("%d", &weight);
  standardWeight = ((hight_cm)-100) * 0.9;
  hight_m = hight_cm / 100;
  bmi = weight / (hight_m * hight_m);
  printf("standardWeight = %f\n", standardWeight);
  printf("BMI = %f\n", bmi);
  return 0;
}
