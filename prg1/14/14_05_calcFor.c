#include <stdio.h>

void print_game(int game[3][3][3], int player) {  // ゲームの描画
  for (int n = 0; n < 3; n++) {
    switch (n) {
      case 0:
        printf("top");
        break;
      case 1:
        printf("mid");
        break;
      case 2:
        printf("bottom");
        break;
      default:
        break;
    }
    for (int i = 0; i < 3; i++) {
      switch (i) {
        case 0:
          printf("        ——  ——  ——\n");
          printf("      / %c / %c / %c /\n", mark(game[i][0][0]),
                 mark(game[i][0][1]), mark(game[i][0][2]));
          break;
        case 1:
          printf("    / ——  ——  —— /\n");
          printf("   / %c / %C / %c /\n", mark(game[i][1][0]),
                 mark(game[i][1][1]), mark(game[i][1][2]));
          break;
        case 2:
          printf(" / ——  ——  —— /\n");
          printf("/ %c / %c / %c /\n", mark(game[i][2][0]), mark(game[i][2][1]),
                 mark(game[i][2][2]));
          printf(" ——  ——  ——\n");
          break;
        default:
          break;
      }
    }
  }
}
