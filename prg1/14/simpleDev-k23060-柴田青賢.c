#include <stdio.h>

void devA(int a, int b, int c) { printf("%s\n", a || c ? "GO" : "NO"); }

int main() {
  devA(0, 0, 0);
  devA(0, 0, 1);
  devA(0, 1, 0);
  devA(0, 1, 1);
  devA(1, 0, 0);
  devA(1, 0, 1);
  devA(1, 1, 0);
  devA(1, 1, 1);
  printf("\n");
  return 0;
}