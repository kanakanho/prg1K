#include <stdio.h>

void printbin(unsigned int n);

int main(void) {
  unsigned int n;
  printf("入力 : ");
  scanf("%d", &n);
  printf("--------------\n");
  printbin(n);

  return 0;
}

void printbin(unsigned int n) {
  int digit = 0;
  unsigned int tmp = n;
  while (tmp > 0) {
    tmp /= 2;
    digit++;
  }
  printf("出力 : ");
  for (int i = digit - 1; i >= 0; i--) {
    printf("%d", (n >> i) & 1);
  }
  printf("\n");
}