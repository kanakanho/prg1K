#include <stdio.h>
#include <stdlib.h>

extern void yomiage(long long n);

char ss[256] = {'\0'};

int main(void) {
  long long n = 0;

  printf("Number ? ");
  // 数値を文字列として入力、数値に変換する処理のコード
  fgets(ss, sizeof(ss), stdin);
  n = atoll(ss);

  printf("%lld = ", n);
  // long long 型の場合 「%d」ではなく
  // 「%lld」とする

    // 処理回数を宣言
  int count = 0;

  // nの桁数を求める
  int digit = 0;
  long long tmp = n;
  while (tmp) {
    tmp /= 10;
    digit++;
  }
  printf("digit = %d\n", digit);
  count = digit / 4;
  printf("count = %d\n", count);

  yomiage(n);
  printf("\n");

  return 0;
}