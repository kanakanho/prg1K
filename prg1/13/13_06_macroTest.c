#include <stdio.h>
#define NUM (10)

int main(int argc, const char* argv[]) {
  int sum = 0;
  // 足し算
  for (int i = 0; i <= NUM; i++) {
    sum += i;
  }
  // 出力
  printf("総和 = %d\n", sum);
  return 0;
}
