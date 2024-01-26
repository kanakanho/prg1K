#include <stdio.h>

unsigned int rrotate(unsigned int x, int n);
unsigned int lrotate(unsigned int x, int n);

int main(void) {
  unsigned int x;
  unsigned int x_right;
  unsigned int x_left;
  int n;
  printf("x = ");
  scanf("%d", &x);
  printf("n = ");
  scanf("%d", &n);

  x_right = rrotate(x, n);
  printf("x_right = %d\n", x_right);
  x_left = lrotate(x, n);
  printf("x_left  = %d\n", x_left);

  return 0;
}

unsigned int rrotate(unsigned int x, int n) {
  return (x >> n) | (x << (32 - n));rr
}

unsigned int lrotate(unsigned int x, int n) {
  return (x << n) | (x >> (32 - n));
}