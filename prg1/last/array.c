#include <stdio.h>
#include <string.h>

int main(void) {
  // printf("\033[2J\033[H");
  char continue_game = 'y';
  printf("event:start");
  printf("立体的な四目並べゲーム\n");
  printf(
      "4*4*"
      "4のフィールドに、縦横斜に同じマークを4つ並べたプレイヤーの勝利です。\n");
  printf("プレイヤーは4*4のマスから自分がマークを落とす場所を選びます。\n");
  printf("マークを落とす場所は、0~Fで指定します。\n");
  printf("場所を選択すると、その縦の列にマークが何もない列であれば一番下に\n");
  printf("そうでない場合はそのマークの上に落ちます\n");
  printf("\n");
  printf("Start Game? (y/n): ");
  scanf("%c", &continue_game);

  while (continue_game == 'y') {
    printf("event:loding");
    // ゲームの初期化
    int play_counter = 0;
    int player = 0;
    int outcome = 0;
    char game[4][4][4] = {{{' ', ' ', ' ', ' '},
                           {' ', ' ', ' ', ' '},
                           {' ', ' ', ' ', ' '},
                           {' ', ' ', ' ', ' '}},
                          {{' ', ' ', ' ', ' '},
                           {' ', ' ', ' ', ' '},
                           {' ', ' ', ' ', ' '},
                           {' ', ' ', ' ', ' '}},
                          {{' ', ' ', ' ', ' '},
                           {' ', ' ', ' ', ' '},
                           {' ', ' ', ' ', ' '},
                           {' ', ' ', ' ', ' '}},
                          {{' ', ' ', ' ', ' '},
                           {' ', ' ', ' ', ' '},
                           {' ', ' ', ' ', ' '},
                           {' ', ' ', ' ', ' '}}};
    while (outcome == 0) {
      printf("event:run\n");
      player = play_counter % 2;
      printf("\033[2J\033[H");
      printf("event:print\n");
      // game画面の描画
      for (int i = 0; i <= 1; i++) {
        if (i == 1) i = 2;
        if (i == 0) {
          printf("top       second\n");
        } else if (i == 2) {
          printf("third     bottom\n");
        }
        printf("%c|%c|%c|%c  %c|%c|%c|%c\n", game[i][0][0], game[i][0][1],
               game[i][0][2], game[i][0][3], game[i + 1][0][0],
               game[i + 1][0][1], game[i + 1][0][2], game[i + 1][0][3]);
        printf("-------  -------\n");
        printf("%c|%c|%c|%c  %c|%c|%c|%c\n", game[i][1][0], game[i][1][1],
               game[i][1][2], game[i][1][3], game[i + 1][1][0],
               game[i + 1][1][1], game[i + 1][1][2], game[i + 1][1][3]);
        printf("-------  -------\n");
        printf("%c|%c|%c|%c  %c|%c|%c|%c\n", game[i][2][0], game[i][2][1],
               game[i][2][2], game[i][2][3], game[i + 1][2][0],
               game[i + 1][2][1], game[i + 1][2][2], game[i + 1][2][3]);
        printf("-------  -------\n");
        printf("%c|%c|%c|%c  %c|%c|%c|%c\n", game[i][3][0], game[i][3][1],
               game[i][3][2], game[i][3][3], game[i + 1][3][0],
               game[i + 1][3][1], game[i + 1][3][2], game[i + 1][3][3]);
      }
      char OX[2] = {'O', 'X'};
      char input_num;
      printf("プレイヤー%dのターンです\n", player);
      printf("0|1|2|3\n");
      printf("-------\n");
      printf("4|5|6|7\n");
      printf("-------\n");
      printf("8|9|A|B\n");
      printf("-------\n");
      printf("C|D|E|F\n");
      printf("マークを落とす場所を選択してください\n");
      scanf(" %c", &input_num);
      // マークを落とす場所を選択
      // 縦の行の特定
      int row[2] = {0, 0};
      if (strcmp(&input_num, "0") == 0)
        row[0] = 0, row[1] = 0;
      else if (strcmp(&input_num, "1") == 0)
        row[0] = 0, row[1] = 1;
      else if (strcmp(&input_num, "2") == 0)
        row[0] = 0, row[1] = 2;
      else if (strcmp(&input_num, "3") == 0)
        row[0] = 0, row[1] = 3;
      else if (strcmp(&input_num, "4") == 0)
        row[0] = 1, row[1] = 0;
      else if (strcmp(&input_num, "5") == 0)
        row[0] = 1, row[1] = 1;
      else if (strcmp(&input_num, "6") == 0)
        row[0] = 1, row[1] = 2;
      else if (strcmp(&input_num, "7") == 0)
        row[0] = 1, row[1] = 3;
      else if (strcmp(&input_num, "8") == 0)
        row[0] = 2, row[1] = 0;
      else if (strcmp(&input_num, "9") == 0)
        row[0] = 2, row[1] = 1;
      else if (strcmp(&input_num, "A") == 0)
        row[0] = 2, row[1] = 2;
      else if (strcmp(&input_num, "B") == 0)
        row[0] = 2, row[1] = 3;
      else if (strcmp(&input_num, "C") == 0)
        row[0] = 3, row[1] = 0;
      else if (strcmp(&input_num, "D") == 0)
        row[0] = 3, row[1] = 1;
      else if (strcmp(&input_num, "E") == 0)
        row[0] = 3, row[1] = 2;
      else if (strcmp(&input_num, "F") == 0)
        row[0] = 3, row[1] = 3;
      // 横の行の特定と入力
      if (strcmp(&game[3][row[0]][row[1]], " ") == 0)
        game[3][row[0]][row[1]] = OX[player];
      else if (strcmp(&game[2][row[0]][row[1]], " ") == 0)
        game[2][row[0]][row[1]] = OX[player];
      else if (strcmp(&game[1][row[0]][row[1]], " ") == 0)
        game[1][row[0]][row[1]] = OX[player];
      else if (strcmp(&game[0][row[0]][row[1]], " ") == 0)
        game[0][row[0]][row[1]] = OX[player];
      else
        printf("その場所にはマークを落とせません\n");
      printf("event:action\n");
      // 勝敗の判定
      // 横の判定
      for (int i = 0; i <= 3; i++) {
        for (int j = 0; j <= 3; j++) {
          if ((game[i][j][0] == ' ') || (game[i][j][0] == game[i][j][1]) &&
                                            (game[i][j][0] == game[i][j][2]) &&
                                            (game[i][j][0] == game[i][j][3]))
            outcome = 0;
          if (game[i][j][0] == game[i][j][1] == game[i][j][2] == game[i][j][3])
            outcome = 1;
        }
      }
      // 縦の判定
      for (int i = 0; i <= 3; i++) {
        for (int j = 0; j <= 3; j++) {
          if ((game[i][0][j] == ' ') || (game[i][0][j] == game[i][1][j]) &&
                                            (game[i][0][j] == game[i][2][j]) &&
                                            (game[i][0][j] == game[i][3][j]))
            outcome = 0;
          if (game[i][0][j] == game[i][1][j] == game[i][2][j] == game[i][3][j])
            outcome = 1;
        }
      }
      // 斜めの判定
      for (int i = 0; i <= 3; i++) {
        if ((game[i][0][0] == ' ') ||
            (game[i][0][0] == game[i][1][1] && game[i][0][0] == game[i][2][2] &&
             game[i][0][0] == game[i][3][3]) ||
            (game[i][0][3] == ' ') ||
            (game[i][0][3] == game[i][1][2] && game[i][0][3] == game[i][2][1] &&
             game[i][0][3] == game[i][3][0]) ||
            (game[0][i][0] == ' ') ||
            (game[0][i][0] == game[1][i][1] && game[0][i][0] == game[2][i][2] &&
             game[0][i][0] == game[3][i][3]) ||
            (game[0][i][3] == ' ') ||
            (game[0][i][3] == game[1][i][2] && game[0][i][3] == game[2][i][1] &&
             game[0][i][3] == game[3][i][0]) ||
            (game[0][0][i] == ' ') ||
            (game[0][0][i] == game[1][1][i] && game[0][0][i] == game[2][2][i] &&
             game[0][0][i] == game[3][3][i]) ||
            (game[0][3][i] == ' ') ||
            (game[0][3][i] == game[1][2][i] && game[0][3][i] == game[2][1][i] &&
             game[0][3][i] == game[3][0][i]))
          outcome = 0;
        else if (game[i][0][0] == game[i][1][1] == game[i][2][2] ==
                     game[i][3][3] ||
                 game[i][0][3] == game[i][1][2] == game[i][2][1] ==
                     game[i][3][0] ||
                 game[0][i][0] == game[1][i][1] == game[2][i][2] ==
                     game[3][i][3] ||
                 game[0][i][3] == game[1][i][2] == game[2][i][1] ==
                     game[3][i][0] ||
                 game[0][0][i] == game[1][1][i] == game[2][2][i] ==
                     game[3][3][i] ||
                 game[0][3][i] == game[1][2][i] == game[2][1][i] ==
                     game[3][0][i])
          outcome = 1;
        else
          outcome = 0;
      }
      printf("event:judge\n");
      if (outcome == 1) {
        if (play_counter % 2 == 1) {
          printf("プレイヤー1の勝利です\n");
          break;
        } else if (play_counter % 2 == 0) {
          printf("プレイヤー2の勝利です\n");
          break;
        }
      }
      play_counter++;
      printf("event:counter");
      if (play_counter == 64) {
        printf("引き分けです\n");
        break;
      }
    }
    printf("event:finish");
    printf("もう一度プレイしますか？(y/n)\n");
    scanf(" %c", &continue_game);
  }
  printf("ゲームを終了します\n");
  return 0;
}