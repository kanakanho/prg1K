//
//  09_03_switch3.c
//
//
//  Created by k23060kk on 2023/06/15.
//

#include <math.h>
#include <stdio.h>

int main(int argc, const char* argv[]) {
  double x;
  int selected;

  printf("x? ");
  scanf("%lf", &x);

  printf("ーーー menu ーーー\n");
  printf("1: 絶対値, 2: 二乗, 3: 三乗\n");

  printf("menu no? ");
  scanf("%d", &selected);

  switch (selected) {
    case 1:
      printf("|%f|", fabs(x));
      break;

    case 2:
      printf("%f ^ 2 = %f\n", x, pow(x, 2));
      break;

    case 3:
      printf("%f ^ 3 = %f\n", x, pow(x, 3));
      break;

    default:
      break;
  }

  return 0;
}