#include <math.h>
#include <stdio.h>

double calcArea(double);
double calcCircumference(double);

int main(int argc, const char* argv[]) {
  double r = 0;
  // 入力
  printf("input r: ");
  scanf("%lf", &r);
  // 出力
  printf("%lf %lf\n", calcArea(r), calcCircumference(r));
}

double calcArea(double r) { return r * r * M_PI; }
double calcCircumference(double r) { return r * 2 * M_PI; }