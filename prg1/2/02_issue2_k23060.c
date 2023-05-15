//
//  02_01_helloWorld.c
//  
//
//  Created by k23060kk on 2023/04/20.
//

#include <stdio.h>

int main(int argc, const char * argv[]){
    int x = 5 , y = 3 , z1 , z2;
    z1 = x / y;
    z2 = x % y;
    printf("%d / %d = %d ... %d\n",x,y,x / y,x % y);
    return 0;
}
