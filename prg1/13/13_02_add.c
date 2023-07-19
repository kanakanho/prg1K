#include <stdio.h>

void addOf(int, int);

int main(int argc, const char* argv[]) {
  // 宣言, 変数は必ず初期化を行う
  int a = 5, b = 10, result = 0;
  //  関数の実行
  addOf(a, b);
  return 0;
}

void addOf(int a, int b) {
  // 出力
  printf("%d + %d = %d\n", a, b, a + b);
}
