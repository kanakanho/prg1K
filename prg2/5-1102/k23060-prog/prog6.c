#include <stdio.h>

void my_strcpy(char *copy, char *original);

int main(void){
    char a[128] = "abc";
    char b[128];

    printf("before\n");
    printf("a = %s\n", a);
    printf("b = %s\n", b);

    my_strcpy(b, a);

    printf("after\n");
    printf("a = %s\n", a);
    printf("b = %s\n", b);

    return 0;
}

void my_strcpy(char *copy, char *original){
    int i = 0;
    while(original[i] != '\0'){
        copy[i] = original[i];
        i++;
    }
    copy[i] = '\0';
}