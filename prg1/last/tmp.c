#include <stdio.h>
#include <stdlib.h>

// プロトタイプ宣言
void game_core(int win_count, int cards[4][13], int* game_tmp);
void card_serect(int cards[4][13], int marks[4], int* i, int* j);
char print_game(int card, int new_card, int mark, int new_mark);
int win_counter(int win_lose, int counter);
char what_card(int);
char what_mark(int);

int main(void) {
  int win_count = 0;
  int game_tmp = 1;
  int cards[4][13] = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13},
                      {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13},
                      {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13},
                      {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13}};
  while (1) {
    game_core(win_count, cards, &game_tmp);
    if (game_tmp == 0) {
      break;
    }
  };
  printf("ゲーム終了\n");
  printf("勝ち：%d 負け：%d\n", win_count, 52 - win_count);
  char next_game;
  printf("次のゲームに進みますか？(y/n): ");
  scanf(" %c", &next_game);
  if (next_game == 'y') {
    main();
  } else {
    printf("またのプレイをお待ちしています\n");
  }
  return 0;
}

int win_counter(int win_lose, int counter) {
  if (win_lose == 1) {
    counter++;
    return counter;
  }
  return counter;
}

void game_core(int win_count, int cards[4][13], int* game_tmp) {
  int marks[4] = {1, 2, 3, 4};
  char judge;
  int mark, new_mark, card, new_card = 0;
  int cardmunber, marknumber = 0;
  card_serect(cards, marks, &mark, &card);
  judge = print_game(card, new_card, mark, new_mark);
  card_serect(cards, marks, &mark, &card);
  int win_lose = 0;
  if (judge == 'h' && card < new_card) {
    printf("win\n");
    win_lose = 1;
  } else if (judge == 'l' && card > new_card) {
    printf("win\n");
    win_lose = 1;
  } else {
    printf("lose\n");
    win_lose = 0;
  }
  win_count = win_counter(win_lose, win_count);
  if (win_count == 26) {
    *game_tmp = 0;
  }
  char which;
  which = print_game(card, new_card, mark, new_mark);
  if (which == 'y') {
    *game_tmp = 1;
  } else {
    *game_tmp = 0;
  }
}

void card_serect(int cards[4][13], int marks[4], int* i, int* j) {
  while (1) {
    *i = rand() % 4;
    *j = rand() % 13;
    if (cards[*i][*j] != ' ') {
      char mark = what_card(*i);
      // printf("%c%c\n", mark, cards[*i][*j]);
      // 引いたカードの値を消す
      cards[*i][*j] = ' ';
      break;
    }
  }
}
char print_game(int card, int new_card, int mark, int new_mark) {
  char tmp;
  char mark_string = what_mark(mark);
  char new_mark_string = what_mark(new_mark);
  char card_srring = what_card(card);
  char new_card_string = what_card(new_card);
  printf("A<2<3<4<5<6<7<8<9<10<J<Q<K    同じ数字は負け\n");
  printf("\n");
  printf("cpu card\n");
  printf("------\n");
  printf("|%c%c|\n", mark_string, card_srring);
  printf("------\n");
  printf("\n");
  printf("player card\n");
  printf("------\n");
  printf("|%c%c|\n", new_mark_string, new_card_string);
  printf("------\n");
  printf("\n");
  if (new_card == 0) {
    printf("high or low? (h/l) :");
    scanf(" %c", &tmp);
    return tmp;
  } else {
    printf("ゲームを続けますか？(y/n)\n");
    scanf(" %c", &tmp);
    return tmp;
  }
}

char what_mark(int i) {
  if (i == 1) {
    return 'S';
  } else if (i == 2) {
    return 'H';
  } else if (i == 3) {
    return 'D';
  } else if (i == 4) {
    return 'C';
  } else if (i == 0) {
    return '?';
  }
  return 0;
}

char what_card(int i) {
  if (i == 1) {
    return 'A';
  } else if (i == 2) {
    return '2';
  } else if (i == 3) {
    return '3';
  } else if (i == 4) {
    return '4';
  } else if (i == 5) {
    return '5';
  } else if (i == 6) {
    return '6';
  } else if (i == 7) {
    return '7';
  } else if (i == 8) {
    return '8';
  } else if (i == 9) {
    return '9';
  } else if (i == 10) {
    return 'T';
  } else if (i == 11) {
    return 'J';
  } else if (i == 12) {
    return 'Q';
  } else if (i == 13) {
    return 'K';
  } else if (i == 0) {
    return '?';
  }
  return 0;
}