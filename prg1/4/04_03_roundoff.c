//
//  04_03_roundoff.c
//
//
//  Created by k23060kk on 2023/05/11.
//

#include <stdio.h>

int main(int argc, const char* argv[]) {
  double dx;
  int nx;
  printf("dx?");
  scanf("%lf", &dx);
  printf("dx/2 = %f\n", dx / 2);
  nx = dx;
  printf("nx = %d\n", nx);
  printf("nx/2 = %d\n", nx / 2);
  return 0;
}
