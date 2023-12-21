#include <stdio.h>

int calc(int previousTmp, int laterTmp, int n) {
  for (int i = 3; i <= n; i++) {
    if (i % 2 == 0) {
      previousTmp = previousTmp + laterTmp;
      printf("x%d : %d\n", i,previousTmp);
    } else {
      laterTmp = previousTmp + laterTmp;
      printf("x%d : %d\n", i,laterTmp);
    }
  }
  int result;
  if (previousTmp > laterTmp) {
    result = previousTmp;
  } else {
    result = laterTmp;
  }
  return result;
}

int main(void) {
  int x1, x2, previousTmp, laterTmp, x, n;
  x1 = 1;
  x2 = 1;
  previousTmp = x1;
  laterTmp = x2;
  n = 10;
  x = calc(previousTmp, laterTmp, n);
  printf("Result: %d\n", x);
  return 0;
}