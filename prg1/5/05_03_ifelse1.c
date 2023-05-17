//
//  05_03_ifelse1.c
//
//
//  Created by k23060kk on 2023/05/18.
//

#include <stdio.h>

int main(int argc, const char* argv[]) {
  int a;                                 // 変数aを宣言
  printf("a?");                          // プロンプトを表示
  scanf("%d", &a);                       // キーボードから入力
  if (a >= 0) {                          // aが0以上のとき
    printf("aは正の値もしくは0です\n");  // メッセージを表示
  } else {                               // aが0未満のとき
    printf("aは負の値です\n");           // メッセージを表示
  }
  printf("計算終了\n");  // メッセージを表示(必ず表示される
  return 0;
}
