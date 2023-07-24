#include <stdio.h>

int main() {
  int counter = 0;
  int player = counter % 2 + 1;
  char str_player[1];
  sprintf(&str_player, sizeof(str_player), "%d", player);
  printf("%c\n", str_player);
  return 0;
}
