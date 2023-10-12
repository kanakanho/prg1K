#include <stdio.h>
int draw_figure(int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 1; j < size - i; j++) {
      printf(" ");
    }
    printf("*");
    printf("\n");
  }
  return 0;
}