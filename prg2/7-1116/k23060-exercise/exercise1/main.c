#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  // 変数を宣言
  int *p;
  int point;
  int numberOfPeople;
  int sum;
  double average;
  int variance;
  double standardDeviation;

  printf("Number of people ? ");
  scanf("%d", &numberOfPeople);

  // メモリを確保
  if ((p = (int *)malloc(numberOfPeople * sizeof(int))) == NULL) {
    printf("No enough memory.\n");
    exit(1);
  }

  for (int i = 0; i < numberOfPeople; i++) {
    printf("%d. Point ? ", i + 1);
    scanf("%d", &point);
    p[i] = point;
  }

  // 平均を求める
  for (int i = 0; i < numberOfPeople; i++) {
    sum += p[i];
  }
  average = (double)sum / numberOfPeople;
  printf("Average: %f\n", average);

  // 標準偏差を求める
  for (int i = 0; i < numberOfPeople; i++) {
    variance += pow(p[i] - average, 2);
  }
  standardDeviation = sqrt(variance / numberOfPeople);
  printf("Standard deviation: %f\n", standardDeviation);

  free(p);
}