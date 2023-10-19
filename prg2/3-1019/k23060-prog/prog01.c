#include <stdio.h>

int main(void) {
  // 変数の宣言
  int n, m;
  char c, d;

  // アドレスを表示
  printf("int  n のアドレス : %p\n", &n);
  printf("int  m のアドレス : %p\n", &m);
  printf("char c のアドレス : %p\n", &c);
  printf("char d のアドレス : %p\n", &d);

  return 0;
}