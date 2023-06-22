//
//  10_challenge1_k20000.c
//
//
//  Created by k23060kk on 2023/06/22.
//

#include <stdio.h>

int main(int argc, const char* argv[]) {
  int primeNumbers[100] = {0};
  int num = 0;
  int isPrime = 1;

  for (int i = 2; i <= 100; i++) {
    for (int j = 0; j < num; j++) {
      if (i % primeNumbers[j] == 0) {
        isPrime = 0;
        break;
      }
    }

    if (isPrime == 1) {
      primeNumbers[num] = i;
      num++;
    }
    isPrime = 1;
  }

  for (int i = 0; i < num; i++) printf("%d, ", primeNumbers[i]);
  printf("\n");

  return 0;
}
