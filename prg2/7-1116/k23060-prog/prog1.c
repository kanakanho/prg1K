#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int *p = (int *)malloc(4 * sizeof(int));
  for (int i = 0; i < 4; i++) {
    p[i] = i + 1;
  }
  for (int i = 0; i < 4; i++) {
    printf("%d\n", i, p[i]);
  }

  free(p);
}