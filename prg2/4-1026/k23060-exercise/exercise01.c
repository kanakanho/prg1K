#include <stdio.h>

void swap(int *px, int *py);
void sort(int *a, int *b);
void bubble(int size, int *array);
void print(int num, char *name, int *array);

int main(void) {
  int array[] = {10, 30, 80, 50, 60, 70, 100, 40, 90, 20};
  int size = sizeof array / sizeof(int);

  print(size, "a", array);

  bubble(size, array);

  print(size, "a", array);
  return 0;
}

void swap(int *px, int *py) {
  int tmp = *px;
  *px = *py;
  *py = tmp;
}

void sort(int *a, int *b) {
  if (*a > *b) {
    swap(a, b);
  }
}

void bubble(int size, int *array) {
  while (size > 0) {
    for (int i = 1; i < size; i++) {
      sort(&array[i - 1], &array[i]);
    }
    size -= 1;
  }
}

void print(int size, char *name, int *array) {
  for (int i = 0; i < size; i++) {
    printf("%s[%d] = %d\n", name, i, array[i]);
  }
}