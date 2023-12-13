#include <stdio.h>

struct location {
  double lat;
  double lon;
  char address[256];
};

void print_location(struct location place) {
  printf("緯度 %f\n", place.lat);
  printf("経度 %f\n", place.lon);
  printf("住所 %s\n", place.address);
}

int main(void) {
  struct location p1 = {35.18354808909407, 137.1130311676068,
                  "〒470-0356 愛知県豊田市八草町八千草１２４７"};
  struct location p2 = {35.182213422066575, 136.9489659003134,
                            "〒464-0083 愛知県名古屋市千種区若水３丁目２−１２"};

  printf("愛知工業大学\n");
  print_location(p1);
  printf("愛工大名電\n");
  print_location(p2);

  return 0;
}