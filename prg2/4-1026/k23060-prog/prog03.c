#include <stdio.h>

int main(void){
    double a[3];

    // アドレスを表示
    printf("a[0] のアドレス %p\n", &a[0]);
    printf("a[1] のアドレス %p\n", &a[1]);
    printf("a[2] のアドレス %p\n", &a[2]);
    
    return 0;
}