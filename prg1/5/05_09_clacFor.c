//
//  05_09_clacFor.c
//
//
//  Created by k23060kk on 2023/05/18.
//

#include <stdio.h>

int main(int argc, const char* argv[]) {
  int sum = 0;                     // 合計値を格納する変数
  for (int i = 0; i <= 10; i++) {  // iが0から10以下の間繰り返す
    sum += i;                      // sumにiを加える
  }
  printf("%d\n", sum);  // sumを表示
}
