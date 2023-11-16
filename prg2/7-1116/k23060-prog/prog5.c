#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int number;
  printf("number ? ");
  scanf("%d", &number);

  int *p = (int *)malloc(number * sizeof(int));
  for (int i = 0; i < number; i++) {
    printf("p[%d] ? ", i);
    scanf("%d", &p[i]);
  }
  for (int i = number - 1; i >= 0; i--) {
    printf("%d\n", p[i]);
  }
  free(p);
}