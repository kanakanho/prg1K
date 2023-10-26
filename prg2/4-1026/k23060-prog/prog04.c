#include <stdio.h>

int main(void) {
  int a[5] = {0, 1, 2, 3, 4};
  int *pa = a;
  for (int i = 0; i < 5; i++) {
    if (i == 0) {
      printf("pa   のアドレス %p\n", &pa + i);
    } else {
      printf("pa+%d のアドレス %p\n", i, &pa + i);
    }
  }
  for (int i = 0; i < 5; i++) {
    printf("a[%d] のアドレス %p\n", i, &a + i);
  }
  return 0;
}