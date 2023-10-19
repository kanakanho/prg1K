// ２つの変数(int)と，それを指すポインタを用意する．
// ポインタを用いて２つの変数の値を変更せよ

#include <stdio.h>

int main(void) {
  // 変数の宣言
  int n = 1;
  int m = 2;
  // ポインタの宣言
  int *pointer_n = &n;
  int *pointer_m = &m;

  printf("before n = %d , m = %d\n", n, m);

  // ポインタを用いて変数の値を変更
  // pointer_? が見ているアドレスの値を変更する
  *pointer_n = 3;
  *pointer_m = 4;

  printf("after  n = %d , m = %d\n", n, m);

  return 0;
}