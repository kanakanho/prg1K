#include <stdio.h>
#define Repeat 100

int main(void) {
  // 100回繰り返す
  for (int i = 0; i < Repeat; i++) {
    printf("hoge");
    if (1 == i % 2) {
      if (2 == i % 3) {
        // 2の倍数かつ3の倍数
        printf("foobar");
      } else {
        // 2の倍数
        printf("foo");
      }
    } else if (2 == i % 3) {
      // 3の倍数
      printf("bar");
    }
    printf("\n");
  }
  return 0;
}