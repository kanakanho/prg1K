#include <math.h>
#include <stdio.h>

int main(void) {
  int r;
  double circle, area;
  printf("半径? ");
  scanf("%d", &r);
  circle = r * 2 * M_PI;
  area = r * r * M_PI;
  printf("円周 : %f\n", circle);
  printf("面積 : %f\n", area);
  return 0;
}