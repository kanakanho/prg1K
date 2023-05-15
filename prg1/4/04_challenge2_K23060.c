//
//  04_challenge2_K20000.c
//
//
//  Created by k23060kk on 2023/05/11.
//

#include <stdio.h>

int main(int argc, const char* argv[]) {
  // 変数を定義
  int total, legs, crane = 0, tortoise;
  // totalを入力
  printf("total?");
  scanf("%d", &total);
  // legsを入力
  printf("legs?");
  scanf("%d", &legs);
  // つるかめ算が可能か判別
  if (legs % 2 == 0) {
    // かめの最大値
    tortoise = legs / 4;
    crane = total - tortoise;
    // 条件が揃うまで繰り返す
    while (legs != tortoise * 4 + crane * 2) {
      tortoise -= 1;
      crane = total - tortoise;
    }
    printf("crane = %d, tortoise = %d\n", crane, tortoise);
  } else {
    printf("cannot be combined\n");
  }
  return 0;
}
