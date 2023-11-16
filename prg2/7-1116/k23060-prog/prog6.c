#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    // 文字列を定義
    char *str1="ABCDE";
    char *str2="XYZ";
    char *str;
    
    // サイズを計算
    int str1Size = strlen(str1);
    int str2Size = strlen(str2);
    int strSize = str1Size + str2Size + 1;

    // メモリを確保
    str = (char *)malloc(strSize * sizeof(char));

    // 文字列を結合
    strcpy(str, str1);
    strcat(str, str2);

    // 結果を表示
    printf("%s\n", str);

    free(str);
}