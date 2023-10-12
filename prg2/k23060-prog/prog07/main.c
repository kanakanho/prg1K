#include <stdio.h>
#define Repeat 10

int main(void) {
  // 10回繰り返す
  for (int i = 0; i < Repeat; i++) {
    printf("hoge");
    // 3の倍数回と最後のとき出力
    if (2 == i % 3 || 9 == i) {
      printf("\n");
    }
  }
  return 0;
}