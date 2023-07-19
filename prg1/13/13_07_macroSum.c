#include <stdio.h>
#define NUM_MIN (5)
#define NUM_MAX (15)

int main(int argc, const char* argv[]) {
  int sum = 0;
  // 足し算
  for (int i = NUM_MIN; i <= NUM_MAX; i++) {
    sum += i;
  }
  // 出力
  printf("総和 = %d\n", sum);
  return 0;
}
