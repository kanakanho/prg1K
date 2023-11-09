#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void) {
  char input[] = "abc112dEf";
  int size = sizeof(input) / sizeof(input[0]);
  char output[size];

  for (int i = 0; i < size; i++) {
    output[i] = toupper(input[i]);
  }

  printf("%s\n", output);
  return 0;
}