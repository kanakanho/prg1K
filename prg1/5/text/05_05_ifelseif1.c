






#include <stdio.h>

int main(int argc, const char* argv[]) {
  int a;                          
  int b;                          
  printf("a?");                   
  scanf("%d", &a);                
  printf("b?");                   
  scanf("%d", &b);                
  if (a == 0) {                   
    printf("aは0です\n");         
  } else if (a >= b) {            
    printf("a は b 以上です\n");  
  } else {                        
    printf("a は b 未満です\n");  
  }
  return 0;
}
