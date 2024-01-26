#include <stdio.h>

char string_reverse(char *str);
char change_hex(int n);
void change(int n, char *n_hex);

int main(void) {
  int n;
  char n_hex[3] = "\0";
  printf("入力 : ");
  scanf("%d", &n);
  printf("--------------\n");
  change(n, n_hex);
  printf("出力 : %s\n", n_hex);
  return 0;
}

char string_reverse(char *str) {
  int i = 0;
  int j = 0;
  while (str[j] != '\0') {
    j++;
  }
  j -= 1;
  while (i < j) {
    char tmp = str[i];
    str[i] = str[j];
    str[j] = tmp;
    i++;
    j--;
  }
  return *str;
}

char change_hex(int n) {
  if (n < 10) {
    return '0' + n;
  }
  switch (n) {
    case 10:
      return 'A';
    case 11:
      return 'B';
    case 12:
      return 'C';
    case 13:
      return 'D';
    case 14:
      return 'E';
    case 15:
      return 'F';
    default:
      return '0';
  }
}

void change(int n, char *n_hex) {
  int i = 0;
  do {
    n_hex[i++] = change_hex(n % 16);
    n /= 16;
  } while (n > 0 && i < 256);
  n_hex[i] = '\0';
  string_reverse(n_hex);
}
