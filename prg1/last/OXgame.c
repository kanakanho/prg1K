#include <stdio.h>

int main(int argc, const char* argv[]) {
  printf("\033[2J\033[H");
  char OX[3] = {'O', 'X', ' '};
  char continue_game = 'y';

  while (continue_game == 'y') {
    // ゲームの初期化
    int play_counter = 0;
    int player_counter[2] = {0, 0};
    int outcome = 3;
    // game画面の宣言
    char game[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    while (outcome == 3) {
      // プレイ回数のカウント、現在のプレイヤーの判定
      play_counter++;
      int player = play_counter % 2;

      // 入力の宣言
      int input = 0;

      printf("%c|%c|%c|1|2|3\n", game[0][0], game[0][1], game[0][2]);
      printf("-----|-----\n");
      printf("%c|%c|%c|4|5|6\n", game[1][0], game[1][1], game[1][2]);
      printf("-----|-----\n");
      printf("%c|%c|%c|7|8|9\n", game[2][0], game[2][1], game[2][2]);

      printf("%c側 %d回目\n", OX[player], player_counter[player] + 1);
      printf("%c を入力する場所: ", OX[player]);
      scanf("%d", &input);
      printf("\033[2J\033[H");

      // 入力の処理
      int row = (input - 1) / 3;
      int col = (input - 1) % 3;
      if (game[row][col] == ' ') {
        game[row][col] = OX[player];
      } else {
        printf("無効な入力です。別の場所を選んでください。\n");
        continue;
      }

      // game画面の描画
      printf("%c|%c|%c\n", game[0][0], game[0][1], game[0][2]);
      printf("-----\n");
      printf("%c|%c|%c\n", game[1][0], game[1][1], game[1][2]);
      printf("-----\n");
      printf("%c|%c|%c\n", game[2][0], game[2][1], game[2][2]);
      printf("\n");

      // 勝敗の判定
      // 縦横斜に同じOXが並んでいるか
      for (int i = 0; i < 2; i++) {
        if ((game[0][0] == OX[i] && game[0][1] == OX[i] &&
             game[0][2] == OX[i]) ||
            (game[1][0] == OX[i] && game[1][1] == OX[i] &&
             game[1][2] == OX[i]) ||
            (game[2][0] == OX[i] && game[2][1] == OX[i] &&
             game[2][2] == OX[i]) ||
            (game[0][0] == OX[i] && game[1][0] == OX[i] &&
             game[2][0] == OX[i]) ||
            (game[0][1] == OX[i] && game[1][1] == OX[i] &&
             game[2][1] == OX[i]) ||
            (game[0][2] == OX[i] && game[1][2] == OX[i]) ||
            (game[0][0] == OX[i] && game[1][1] == OX[i] &&
             game[2][2] == OX[i]) ||
            (game[0][2] == OX[i] && game[1][1] == OX[i] &&
             game[2][0] == OX[i])) {
          outcome = i;
          break;
        }
      }
      printf("\033[2J\033[H");
      // 9回目までに勝敗が決まらなかったら引き分け
      if (play_counter == 9) outcome = 2;
    }
    if (outcome == 2)
      printf("引き分け\n");
    else
      printf("%cの勝ち\n", OX[outcome]);

    continue_game = ' ';
    printf("continue? (y/n): ");
    scanf(" %c", &continue_game);
    getchar();  // 改行文字を読み捨てる

    if (continue_game == 'y') {
      printf("ゲームを続けます\n");
    } else {
      printf("ゲーム終了!\n");
      break;
    }
  }
  return 0;
}
