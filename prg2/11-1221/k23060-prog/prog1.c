#include <math.h>
#include <stdio.h>

int multiplier(int a, int n, int k) {
  int result = 0;
  int tmp;
  for (int i = k; i <= n; i++) {
    tmp = pow(a, n - i);
    result = result + tmp;
  }
  return result;
}

int main(void) {
  int a, n, k = 0;
  a = 4;
  n = 10;

  int result;
  result = multiplier(a, n, k);
  printf("Result: %d\n", result);
  return 0;
}