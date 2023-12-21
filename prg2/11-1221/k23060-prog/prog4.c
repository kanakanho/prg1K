#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int n = 10;
  int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int i, j, tmp;
  srand(time(NULL));

  for (i = n - 1; i >= 1; i--) {
    j = rand() % (i + 1);
    tmp = a[j];
    a[j] = a[i];
    a[i] = tmp;
  }
  for (i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
  return 0;
}