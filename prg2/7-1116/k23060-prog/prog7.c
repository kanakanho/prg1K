#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int *pointer = (int *)malloc(1 * sizeof(int));
  int tmpNum;
  int i = 0;

  do {
    printf("number? ");
    scanf("%d", &tmpNum);

    if (tmpNum >= 0) {
      pointer[i] = tmpNum;
      i += 1;

      pointer = (int *)realloc(pointer, (i + 1) * sizeof(int));
      if (pointer == NULL) {
        printf("Failed to allocate memory.\n");
        return 1;
      }
    }
  } while (tmpNum >= 0);

  for (int j = 0; j < i; j++) {
    printf("%d", pointer[j]);
  }
  printf("\n");

  free(pointer);
}