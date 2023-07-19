#include <math.h>
#include <stdio.h>

int main(int argc, const char* argv[]) {
  double theta, rad = 0;
  printf("input: ");
  scanf("%lf", &theta);
  rad = theta * M_PI / 180;
  printf("sin (%lf) = %lf\n", theta, sin(rad));
  return 0;
}