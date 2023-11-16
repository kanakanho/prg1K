#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int *p;
  if ((p = (int *)malloc(4 * sizeof(int))) == NULL) {
    printf("No enough memory.\n");
    exit(1);
  }
  for (int i = 0; i < 4; i++) {
    p[i] = i + 1;
  }
  for (int i = 0; i < 4; i++) {
    printf("%d\n", i, p[i]);
  }
  free(p);
}