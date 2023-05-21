






#include <stdio.h>

int isPrimeNumber(int n) {
  if (n <= 1) return 0;          
  for (int i = 2; i < n; i++) {  
    if (n % i == 0) return 0;    
  }
  return 1;
}

int main(int argc, const char* argv[]) {
  int n;            
  printf("n?");     
  scanf("%d", &n);  
  if (isPrimeNumber(n) == 0)
    printf("素数ではありません\n");
  else
    printf("素数です\n");
  return 0;
}
