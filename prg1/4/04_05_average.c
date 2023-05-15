//
//  04_05_average.c
//
//
//  Created by k23060kk on 2023/05/11.
//

#include <stdio.h>

int main(int argc, const char* argv[]) {
  int n1, n2, n3;
  double a;
  printf("No.1?");
  scanf("%d", &n1);
  printf("No.2?");
  scanf("%d", &n2);
  printf("No.3?");
  scanf("%d", &n3);
  a = (n1 + n2 + n3) / 3.0;
  printf("average = %f\n", a);
  return 0;
}
