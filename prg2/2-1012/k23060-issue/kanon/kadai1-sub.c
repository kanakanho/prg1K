#include <stdio.h>

extern char ss[256];

// 関数プロトタイプ
void printNum(int num);
void printRank(int num);

void yomiage(long long n) {
  // 処理回数を宣言
  int count = 0;

  // nの桁数を求める
  int digit = 0;
  long long tmp = n;
  while (tmp) {
    tmp /= 10;
    digit++;
  }

  count = digit / 4;

  while (count > 0) {
    // 変換したい数値を16で割った余りを取得
    int bit = n % (10000 ^ count);

    // 余りを文字に変換
    printNum(bit % 1000);
    if (bit % 1000 != 0) {
      printf("千");
    }

    bit /= 10;

    printNum(bit % 100);
    if (bit % 100 != 0) {
      printf("百");
    }

    bit /= 10;

    printNum(bit % 10);
    if (bit % 10 != 0) {
      printf("十");
    }

    bit /= 10;

    printNum(bit);

    n /= 10000;

    printRank(count);
    count -= 1;
  }
}

void printRank(int num) {
  switch (num) {
    case 2:
      printf("万");
      break;
    case 3:
      printf("億");
      break;
    case 4:
      printf("兆");
      break;
    default:
      break;
  }
}

void printNum(int num) {
  switch (num) {
    case 1:
      printf("一");
      break;
    case 2:
      printf("二");
      break;
    case 3:
      printf("三");
      break;
    case 4:
      printf("四");
      break;
    case 5:
      printf("五");
      break;
    case 6:
      printf("六");
      break;
    case 7:
      printf("七");
      break;
    case 8:
      printf("八");
      break;
    case 9:
      printf("九");
      break;
  }
}
