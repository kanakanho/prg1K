#include <stdio.h>
#include <string.h>

int main(void){
    char str1[128] = "abc";
    char str2[] = "cde";
    char *str = "fgh";
    
    printf("strlen\n");
    printf("str1 : %lu\n", strlen(str1));
    printf("str2 : %lu\n", strlen(str2));
    printf("str  : %lu\n", strlen(str));

    printf("sizeof\n");
    printf("str1 : %ld\n", sizeof(str1));
    printf("str2 : %ld\n", sizeof(str2));
    printf("str  : %ld\n", sizeof(str));
    return 0;
}