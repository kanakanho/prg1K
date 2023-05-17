//
//  05_07_ifand.c
//
//
//  Created by k23060kk on 2023/05/18.
//

#include <stdio.h>

int main(int argc, const char* argv[]) {
  int a;                                          // 変数aを宣言
  int b;                                          // 変数bを宣言
  printf("a?");                                   // a?を表示
  scanf("%d", &a);                                // キーボードから入力
  printf("b?");                                   // b?を表示
  scanf("%d", &b);                                // キーボードから入力
  if (a > 0 && b > 0) {                           // a>0かつb>0のとき
    printf("aとbは正です\n");                     // メッセージを表示
  } else {                                        // a<=bまたはb<=0のとき
    printf("aとbのどちらかは負もしくは0です\n");  // メッセージを表示
  }
  return 0;
}
