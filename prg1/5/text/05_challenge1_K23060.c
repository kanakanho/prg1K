






#include <stdio.h>

int main(int argc, const char* argv[]) {
  int dayOfWeek;  
  int time;       
  int isOpen[2][7] = {{0, 1, 1, 1, 1, 1, 0},
                      {0, 1, 1, 0, 1, 1, 1}};  
  printf("曜日?");                             
  scanf("%d", &dayOfWeek);                     
  printf("時間帯?");                           
  scanf("%d", &time);                          
  if (isOpen[time][dayOfWeek] == 1) {          
    printf("診察を行っています\n");            
  } else {                                     
    printf("診察は行っていません\n");          
  }
}
