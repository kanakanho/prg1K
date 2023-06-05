






#include <stdio.h>

int main(int argc, const char* argv[]) {
  int input = 0, n = 0;
  printf("input? ");
  scanf("%d", &input);
  while (1 < input) {
    for (int i = 2; i <= input; i++) {
      if (0 == input % i) {
        if (n == 0) {
          printf("%d", i);
          input = input / i;
          n++;
          break;
        } else {
          printf(", %d", i);
          input = input / i;
          n++;
          break;
        }
      }
    }
  }
  printf("\n");
  return 0;
}
