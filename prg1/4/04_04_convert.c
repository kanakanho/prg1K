//
//  04_04_convert.c
//
//
//  Created by k23060kk on 2023/05/11.
//

#include <stdio.h>

int main(int argc, const char* argv[]) {
  int nx, ny;
  double dx, dy;
  printf("nx ny?");
  scanf("%d %d", &nx, &ny);
  printf("nx/ny = %d\n", nx / ny);
  dx = nx;
  dy = ny;
  printf("dx/ny = %f\n", dx / ny);
  printf("nx/ny = %f\n", nx / dy);
  return 0;
}
