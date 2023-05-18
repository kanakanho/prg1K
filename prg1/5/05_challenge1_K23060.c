//
//  05_challenge1_K20000.c
//
//
//  Created by k23060kk on 2023/05/18.
//

#include <stdio.h>

int main(int argc, const char* argv[]) {
  int dayOfWeek;  // 変数dayOfWeekを宣言
  int time;       // 変数timeを宣言
  int isOpen[2][7] = {{0, 1, 1, 1, 1, 1, 0},
                      {0, 1, 1, 0, 1, 1, 1}};  // 配列listを宣言
  printf("曜日?");                             // 曜日?を表示
  scanf("%d", &dayOfWeek);                     // キーボードから入力
  printf("時間帯?");                           // 時間帯?を表示
  scanf("%d", &time);                          // キーボードから入力
  if (isOpen[time][dayOfWeek] == 1) {          // 配列listの値が1のとき
    printf("診察を行っています\n");            // メッセージを表示
  } else {                                     // 配列listの値が0のとき
    printf("診察は行っていません\n");          // メッセージを表示
  }
}
