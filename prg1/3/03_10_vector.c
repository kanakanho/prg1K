//
//  03_09_xxx.c
//
//
//  Created by k23060kk on 2023/04/27.
//

#include <stdio.h>

int main(int argc, const char* argv[]) {
  int x, y;
  printf("(x,y)?");
  scanf("(%d,%d)", &x, &y);
  printf("(%d,%d)->(%d,%d)\n", x, y, x * 2, y * 2);
  return 0;
}
