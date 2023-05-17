






#include <stdio.h>

int main(int argc, const char* argv[]) {
  int a;                        
  int b;                        
  printf("a?");                 
  scanf("%d", &a);              
  printf("b?");                 
  scanf("%d", &b);              
  if (a > 0 && b == 0) {        
    printf("A\n");              
  } else if (a > 0 && b > 0) {  
    printf("B\n");              
  } else if (a > 0 && b < 0) {  
    printf("C\n");              
  } else {                      
    printf("D\n");              
  }
  return 0;
}
