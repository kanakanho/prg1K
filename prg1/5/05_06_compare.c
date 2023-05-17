//
//  05_06_compare.c
//
//
//  Created by k23060kk on 2023/05/18.
//

#include <stdio.h>

int main(int argc, const char* argv[]) {
  int a;                   // 変数aを宣言
  int b;                   // 変数bを宣言
  printf("a b?");          // a b?を表示
  scanf("%d %d", &a, &b);  // キーボードから入力
  if (a > b) {             // a>bのとき
    printf("a > b\n");     // メッセージを表示
  } else if (a == b) {     // a=bのとき
    printf("a == b\n");    // メッセージを表示
  } else {                 // a<bのとき
    printf("a < b\n");     // メッセージを表示
  }
  return 0;
}
