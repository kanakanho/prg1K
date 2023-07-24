#include <stdio.h>

void devA(int a, int b, int c) {
  if (a == 1)
    printf("GO");
  else if (b == 1 && c == 1)
    printf("GO");
  else if (b == 0 && c == 1)
    printf("GO");
  else
    printf("NO");
}
