//
//  06_01_if.c
//
//
//  Created by k23060kk on 2023/05/25.
//

#include <stdio.h>

int main(int argc, const char* argv[]) {
  int a;                        // 変数aを宣言
  printf("a? ");                // a?を表示
  scanf("%d", &a);              // キーボードから入力
  if (a == 0) {                 // a=0のとき
    printf("aは0です\n");       // メッセージを表示
  } else if (a > 0) {           // a>=bのとき
    printf("aは正の値です\n");  // メッセージを表示
  } else {                      // a<bのとき
    printf("aは負の値です\n");  // メッセージを表示
  }
  return 0;
}
