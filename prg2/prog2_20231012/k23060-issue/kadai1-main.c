#include <stdio.h>
#include <stdlib.h>

extern void yomiage(long long n);
char ss[256] = {'\0'};

int main() {
  // 文字列は charの配列 (詳細は後日)
  // int よりも大きい整数値を扱える型
  long long n = 0;

  printf("Number ? ");
  // 数値を文字列として入力、数値に変換する処理のコード
  fgets(ss, sizeof(ss), stdin);
  n = atoll(ss);

  printf("%lld = ", n);
  // long long 型の場合 「%d」ではなく
  // 「%lld」とする

  // char* ss = (char*)malloc(sizeof(char) * 100);


  yomiage(n);
  printf("\n");

  // free(ss);

  return 0;
}