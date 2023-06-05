//
//  08_01_rectangle.c
//
//
//  Created by k23060kk on 2023/06/8.
//

#include <stdio.h>

int main(int argc, const char* argv[]) {
  int w = 0, h = 0;
  printf("w h? ");
  scanf("%d %d", &w, &h);
  for (int i = 0; i < w; i++) {
    for (int j = 0; j < h; j++) {
      printf("#");
    }
    printf("\n");
  }
  return 0;
}
