#include <math.h>
#include <stdio.h>

double deg2Rad(double);

int main(int argc, const char* argv[]) {
  double theta, rad = 0;
  printf("input: ");
  scanf("%lf", &theta);
  rad = deg2Rad(theta);
  printf("sin (%lf) = %lf\n", theta, sin(rad));
  return 0;
}

double deg2Rad(double theta) { return theta * M_PI / 180; }