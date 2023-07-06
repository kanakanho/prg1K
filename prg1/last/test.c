#include <stdio.h>
#include <string.h>

#define BAR_CHAR '|'
#define SPACE_CHAR ' '

void generateBarcode(const char* data) {
  int i, j, k;
  int len = strlen(data);
  int codeWidth = len * 6 + 2;

  // バーコードの上部
  for (i = 0; i < codeWidth; i++) {
    printf("-");
  }
  printf("\n");

  // バーコードの本体
  for (i = 0; i < len; i++) {
    char currentChar = data[i];

    for (j = 0; j < 6; j++) {
      if ((currentChar >> (5 - j)) & 1) {
        printf("%c", BAR_CHAR);
      } else {
        printf("%c", SPACE_CHAR);
      }
    }
  }
  printf("\n");

  // バーコードの下部
  for (k = 0; k < codeWidth; k++) {
    printf("-");
  }
  printf("\n");
}

int main() {
  char data[] = "123456";
  generateBarcode(data);
  return 0;
}
