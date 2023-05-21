//
//  06_04_clacFor.c
//
//
//  Created by k23060kk on 2023/05/25.
//

#include <stdio.h>

int main(int argc, const char* argv[]) {
  int sum = 0;                             // 合計値を格納する変数
  for (int i = 0; i <= 10; i++) sum += i;  // sumにiを加算
  printf("%d\n", sum);                     // sumを表示
  return 0;
}
