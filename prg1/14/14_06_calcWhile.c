#include <stdio.h>

int main(int argc, const char* argv[]) {
  int i, n, sum = 0;
  printf("n? ");
  scanf("%d", &n);
  while (i <= n) {
    sum += i;
    i++;
  }
  printf("1から%dまでの和は %d\n", n, sum);
  return 0;
}
