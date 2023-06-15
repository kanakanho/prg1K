//
//  09_05_arrayloop.c
//
//
//  Created by k23060kk on 2023/06/15.
//

#include <stdio.h>

int main(int argc, const char* argv[]) {
  int array[100] = {0};

  for (int i = 0; i < 100; i++) array[i] = i;
  for (int i = 0; i < 100; i++) printf("array[%d]: %d\n", i, array[i]);

  return 0;
}