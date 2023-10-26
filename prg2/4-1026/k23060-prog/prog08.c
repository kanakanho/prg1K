#include <stdio.h>

void mul(int num, int *array);
void print(int num, char *name, int *array);

int main(void) {
  int a[5] = {10, 20, 30, 40, 50};
  int b[4] = {3, 4, 5, 6};
  int numA, numB;
  numA = sizeof a / sizeof(int);
  numB = sizeof b / sizeof(int);

  print(numA, "a", a);
  print(numB, "b", b);

  mul(numA, a);
  mul(numB, b);

  print(numA, "a", a);
  print(numB, "b", b);
  return 0;
}

void mul(int num, int *array) {
  for (int i = 0; i < num; i++) {
    array[i] *= 10;
  }
}

void print(int num, char *name, int *array) {
  for (int i = 0; i < num; i++) {
    printf("%s[%d] = %d\n", name, i, array[i]);
  }
}