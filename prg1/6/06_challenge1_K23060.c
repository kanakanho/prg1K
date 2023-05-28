//
//  06_challenge1_K23060.c
//
//
//  Created by k23060kk on 2023/05/18.
//

#include <stdio.h>

int isPrimeNumber(int n) {
  if (n <= 1) return 0;        // 1以下の数は素数ではない
  for (int i = 2; i < n; i++)  // 2からn-1までの数で割り切れるか調べる
    if (n % i == 0) return 0;  // 割り切れる数があれば素数ではない
  return 1;
}

int main(int argc, const char* argv[]) {
  int n;            // 変数nを宣言
  printf("n? ");    // n?を表示
  scanf("%d", &n);  // キーボードから入力
  if (isPrimeNumber(n) == 0)
    printf("素数ではありません\n");
  else
    printf("素数です\n");
  return 0;
}
