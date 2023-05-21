//
//  06_08_even2.c
//
//
//  Created by k23060kk on 2023/05/25.
//

#include <stdio.h>

int main(int argc, const char* argv[]) {
  for (int i = 0; i <= 10; i += 2)
    if (i % 2 == 0) printf("%d\n", i);
  return 0;
}
