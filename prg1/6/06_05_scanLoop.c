//
//  06_05_scanLoop.c
//
//
//  Created by k23060kk on 2023/05/25.
//

#include <stdio.h>

int main(int argc, const char* argv[]) {
  int a;  // 変数aを宣言
  for (int i = 1; i <= 5; i++) {
    printf("a? ");             // a?を表示
    scanf("%d", &a);           // キーボードから入力
    printf("%d: %d\n", i, a);  // iとaを表示
  }
  return 0;
}
