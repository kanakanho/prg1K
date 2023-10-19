#include <math.h>
#include <stdio.h>

int main(void) {
  for (int i = 0; i <= 360; i += 10) {
    printf("%d,%f\n", i, sin(i * M_PI / 180));
  }
  return 0;
}