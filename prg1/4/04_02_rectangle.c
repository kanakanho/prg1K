//
//  04_02_rectangle.c
//
//
//  Created by k23060kk on 2023/05/11.
//

#include <stdio.h>

int main(int argc, const char* argv[]) {
  double width, height, area;
  printf("width?");
  scanf("%lf", &width);
  printf("height?");
  scanf("%lf", &height);
  area = width * height;
  printf("area = %f\n", area);
  return 0;
}
