#include <stdio.h>

void mul(int *a);
void print(int *a);

int main(void) {
  int a[5] = {10, 20, 30, 40, 50};
  print(a);
  mul(a);
  print(a);
  return 0;
}

void mul(int *a) {
  for (int i = 0; i < 5; i++) {
    a[i] *= 10;
  }
}

void print(int *a) {
  for (int i = 0; i < 5; i++) {
    printf("a[%d] = %d\n", i, a[i]);
  }
}