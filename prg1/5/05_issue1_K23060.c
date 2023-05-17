//
//  05_issue1_K23060.c
//
//
//  Created by k23060kk on 2023/05/18.
//

#include <stdio.h>

int main(int argc, const char* argv[]) {
  int x;                                  // 変数xを宣言
  printf("x?");                           // プロンプトを表示
  scanf("%d", &x);                        // キーボードから入力
  if (x != 0) {                           // xが0のとき
    if (x % 2) {                          // xが奇数のとき
      printf("2の倍数ではありません\n");  // メッセージを表示
    } else {                              // xが偶数のとき
      printf("2の倍数です\n");            // メッセージを表示
    }
    if (x % 3) {                          // xが3の倍数のとき
      printf("3の倍数ではありません\n");  // メッセージを表示
    } else {                              // xが3の倍数でないとき
      printf("3の倍数です\n");            // メッセージを表示
    }
  } else {                              // xが0のとき
    printf("2の倍数ではありません\n");  // メッセージを表示
    printf("3の倍数ではありません\n");  // メッセージを表示
  }
  return 0;
}
