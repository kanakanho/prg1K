//
//  06_03_loopNum.c
//
//
//  Created by k23060kk on 2023/05/25.
//

#include <stdio.h>

int main(int argc, const char* argv[]) {
  int n;                         // 変数nを宣言
  printf("n? ");                 // n?を表示
  scanf("%d", &n);               // キーボードから入力
  for (int i = 0; i < n; i++) {  // iがnまで繰り返す
    printf("Hello, World!\n");   // Hello, World!を表示
  }
  return 0;
}
