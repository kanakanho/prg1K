//
//  05_02_if2.c
//
//
//  Created by k23060kk on 2023/05/18.
//

#include <stdio.h>

int main(int argc, const char* argv[]) {
  int a;                               // 変数aを宣言
  int b;                               // 変数bを宣言
  printf("a?");                        // a?を表示
  scanf("%d", &a);                     // キーボードから入力
  printf("b?");                        // b?を表示
  scanf("%d", &b);                     // キーボードから入力
  if (a == b) {                        // a=bのとき
    printf("aとbの値は等しいです\n");  // メッセージを表示
  }
  printf("計算終了\n");  // メッセージを表示(必ず表示される
  return 0;
}
