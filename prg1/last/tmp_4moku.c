#include <stdio.h>
#include <string.h>

void print_game(char game[4][4][4]);
char player_action(char game[4][4][4], char OX[3], int player,
                   int play_counter);
int judge_game(char game[4][4][4]);

int main(void) {
  printf("\033[2J\033[H");
  char OX[3] = {'O', 'X', ' '};
  char continue_game = 'y';

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
  scanf(" %c", &continue_game);  // 先頭の空白文字を無視するように修正

  while (continue_game == 'y') {
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
      player = play_counter % 2;
      printf("\033[2J\033[H");
      print_game(game);
      player_action(game, OX, player, play_counter);
      outcome = judge_game(game);
      if (outcome == 1) {
        printf("プレイヤー1の勝利です\n");
        break;
      } else if (play_counter % 2 == 0) {
        printf("プレイヤー2の勝利です\n");
        break;
      }
    }
    play_counter++;
    if (play_counter == 64) {
      printf("引き分けです\n");
      break;
    }
  }
  print_game(game);
  printf("もう一度プレイしますか？(y/n)\n");
  scanf(" %c", &continue_game);  // 先頭の空白文字を無視するように修正
}
printf("ゲームを終了します\n");
return 0;
}

void print_game(char game[4][4][4]) {
  // game画面の描画
  for (int i = 0; i <= 1; i++) {
    if (i == 0) {
      printf("top       second\n");
    } else if (i == 1) {
      printf("third     bottom\n");
    }
    printf("%c|%c|%c|%c  %c|%c|%c|%c\n", game[i][0][0], game[i][0][1],
           game[i][0][2], game[i][0][3], game[i + 1][0][0], game[i + 1][0][1],
           game[i + 1][0][2], game[i + 1][0][3]);
    printf("-------  -------\n");
    printf("%c|%c|%c|%c  %c|%c|%c|%c\n", game[i][1][0], game[i][1][1],
           game[i][1][2], game[i][1][3], game[i + 1][1][0], game[i + 1][1][1],
           game[i + 1][1][2], game[i + 1][1][3]);
    printf("-------  -------\n");
    printf("%c|%c|%c|%c  %c|%c|%c|%c\n", game[i][2][0], game[i][2][1],
           game[i][2][2], game[i][2][3], game[i + 1][2][0], game[i + 1][2][1],
           game[i + 1][2][2], game[i + 1][2][3]);
    printf("-------  -------\n");
    printf("%c|%c|%c|%c  %c|%c|%c|%c\n", game[i][3][0], game[i][3][1],
           game[i][3][2], game[i][3][3], game[i + 1][3][0], game[i + 1][3][1],
           game[i + 1][3][2], game[i + 1][3][3]);
  }
}

char player_action(char game[4][4][4], char OX[3], int player,
                   int play_counter) {
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
  if (input_num == '0')
    row[0] = 0, row[1] = 0;
  else if (input_num == '1')
    row[0] = 0, row[1] = 1;
  else if (input_num == '2')
    row[0] = 0, row[1] = 2;
  else if (input_num == '3')
    row[0] = 0, row[1] = 3;
  else if (input_num == '4')
    row[0] = 1, row[1] = 0;
  else if (input_num == '5')
    row[0] = 1, row[1] = 1;
  else if (input_num == '6')
    row[0] = 1, row[1] = 2;
  else if (input_num == '7')
    row[0] = 1, row[1] = 3;
  else if (input_num == '8')
    row[0] = 2, row[1] = 0;
  else if (input_num == '9')
    row[0] = 2, row[1] = 1;
  else if (input_num == 'A')
    row[0] = 2, row[1] = 2;
  else if (input_num == 'B')
    row[0] = 2, row[1] = 3;
  else if (input_num == 'C')
    row[0] = 3, row[1] = 0;
  else if (input_num == 'D')
    row[0] = 3, row[1] = 1;
  else if (input_num == 'E')
    row[0] = 3, row[1] = 2;
  else if (input_num == 'F')
    row[0] = 3, row[1] = 3;
  // 横の行の特定と入力
  if (game[3][row[0]][row[1]] != ' ') {  // strcmpを単純な比較に修正
    if (game[2][row[0]][row[1]] != ' ') {
      if (game[1][row[0]][row[1]] != ' ') {
        if (game[0][row[0]][row[1]] != ' ') {
          printf("その場所にはマークを落とせません\n");
          player_action(game, OX, player, play_counter);
        } else
          game[0][row[0]][row[1]] = OX[play_counter];
      } else
        game[1][row[0]][row[1]] = OX[play_counter];
    } else
      game[2][row[0]][row[1]] = OX[play_counter];
  } else
    game[3][row[0]][row[1]] = OX[play_counter];
}

int judge_game(char game[4][4][4]) {
  // 勝敗の判定
  // 横の判定
  for (int i = 0; i <= 3; i++) {
    for (int j = 0; j <= 3; j++) {
      if (game[i][j][0] == game[i][j][1] && game[i][j][1] == game[i][j][2] &&
          game[i][j][2] == game[i][j][3]) {  // 論理演算子の修正
        if (game[i][j][0] == ' ') return 0;
      }
      return 1;
    }
  }
  // 縦の判定
  for (int i = 0; i <= 3; i++) {
    for (int j = 0; j <= 3; j++) {
      if (game[i][0][j] == game[i][1][j] && game[i][1][j] == game[i][2][j] &&
          game[i][2][j] == game[i][3][j]) {  // 論理演算子の修正
        if (game[i][0][j] == ' ') return 0;
      }
      return 1;
    }
  }
  // 斜めの判定
  for (int i = 0; i <= 3; i++) {
    if ((game[i][0][0] == game[i][1][1] && game[i][1][1] == game[i][2][2] &&
         game[i][2][2] == game[i][3][3]) ||
        (game[i][0][3] == game[i][1][2] && game[i][1][2] == game[i][2][1] &&
         game[i][2][1] == game[i][3][0]) ||
        (game[0][i][0] == game[1][i][1] && game[1][i][1] == game[2][i][2] &&
         game[2][i][2] == game[3][i][3]) ||
        (game[0][i][3] == game[1][i][2] && game[1][i][2] == game[2][i][1] &&
         game[2][i][1] == game[3][i][0]) ||
        (game[0][0][i] == game[1][1][i] && game[1][1][i] == game[2][2][i] &&
         game[2][2][i] == game[3][3][i]) ||
        (game[0][3][i] == game[1][2][i] && game[1][2][i] == game[2][1][i] &&
         game[2][1][i] == game[3][0][i])) {  // 論理演算子の修正
      if (game[i][0][0] == ' ' || game[i][0][3] == ' ' ||
          game[0][i][0] == ' ' || game[0][i][3] == ' ' ||
          game[0][0][i] == ' ' || game[0][3][i] == ' ')
        return 0;
    }
    return 1;
  }
}
