#include <stdio.h>

int calc(int x1, int n) {
  int tmp = x1;
  for (int i = 0; i < n; i++) {
    tmp = tmp + 2;
  }
  return tmp;
}

int main(void) {
  int x1, tmp, x, n;
  x1 = 1;
  n = 10;
  x = calc(x1, n);

  printf("Result: %d\n", x);
  return 0;
}