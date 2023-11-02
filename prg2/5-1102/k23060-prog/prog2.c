#include <stdio.h>

int my_strlen(char *str);

int main(void){
    char str1[128] = "abc";
    char str2[] = "cde";
    char *str = "fgh";
    int size;

    size = my_strlen(str1);
    printf("%d\n",size);
    size = my_strlen(str2);
    printf("%d\n",size);
    size = my_strlen(str);
    printf("%d\n",size);
    return 0;
}

int my_strlen(char *str){
    int i = 0;
    while(str[i] != '\0'){
        i++;
    }
    return i;
}