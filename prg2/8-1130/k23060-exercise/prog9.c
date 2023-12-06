#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX 256


typedef struct iris {
    double sepalLength;
    double sepalWidth;
    double petalLength;
    double petalWidth;
    char species[32];
}Iris;

Iris irisSprit(char *str){
    char *pointer;
    Iris iris;
    pointer = strtok(str, ",");

    iris.sepalLength = atof(pointer);
    pointer = strtok(NULL, ",");
    iris.sepalWidth = atof(pointer);
    pointer = strtok(NULL, ",");
    iris.petalLength = atof(pointer);
    pointer = strtok(NULL, ",");
    iris.petalWidth = atof(pointer);
    pointer = strtok(NULL, ",");

    // 改行コードを削除
    pointer[strlen(pointer)-1]='\0';
    static char tmp[64] = {'\0'};
    strcpy(iris.species, pointer);

    return iris;
}

Iris getAverage(Iris *iris_list, int size){

    Iris aveIris;

    double sepalLength_Average = 0;
    double sepalWidth_Average = 0;
    double petalLength_Average = 0;
    double petalWidth_Average = 0;

    for(int j=0;j<size;j++){
        sepalLength_Average += iris_list[j].sepalLength;
        sepalWidth_Average += iris_list[j].sepalWidth;
        petalLength_Average += iris_list[j].petalLength;
        petalWidth_Average += iris_list[j].petalWidth;
    }

    sepalLength_Average = sepalLength_Average/size;
    sepalWidth_Average = sepalWidth_Average/size;
    petalLength_Average = petalLength_Average/size;
    petalWidth_Average = petalWidth_Average/size;

    aveIris.sepalLength = sepalLength_Average;
    aveIris.sepalWidth = sepalWidth_Average;
    aveIris.petalLength = petalLength_Average;
    aveIris.petalWidth = petalWidth_Average;

    return aveIris;
}

Iris getStandardDeviation(Iris *iris_list, int size){
        Iris aveIris = getAverage(iris_list, size);
    
        Iris stdIris;

        for (int i = 0; i<size ; i++){
            stdIris.sepalLength += pow(iris_list[i].sepalLength - aveIris.sepalLength, 2);
            stdIris.sepalWidth += pow(iris_list[i].sepalWidth - aveIris.sepalWidth, 2);
            stdIris.petalLength += pow(iris_list[i].petalLength - aveIris.petalLength, 2);
            stdIris.petalWidth += pow(iris_list[i].petalWidth - aveIris.petalWidth, 2);
        }

        stdIris.sepalLength = sqrt(stdIris.sepalLength/size);
        stdIris.sepalWidth = sqrt(stdIris.sepalWidth/size);
        stdIris.petalLength = sqrt(stdIris.petalLength/size);
        stdIris.petalWidth = sqrt(stdIris.petalWidth/size);

        return stdIris;
}

void printJudgement(Iris *iris_lists ,int size , Iris checkIris){
    double distance = 100.0;
    int index = 0;

    for(int i=0;i<size;i++){
        double newDistance = pow(checkIris.sepalLength - iris_lists[i].sepalLength, 2) + pow(checkIris.sepalWidth - iris_lists[i].sepalWidth, 2) + pow(checkIris.petalLength - iris_lists[i].petalLength, 2) + pow(checkIris.petalWidth - iris_lists[i].petalWidth, 2);

        if(distance > newDistance){
            distance = newDistance;
            index = i;
        }
    }
    printf("%s\n", iris_lists[index].species);
    return ;
}

int main(int argc, const char* argv[]){

    Iris lists[MAX];
    int size = 0;
    char line[MAX];
    Iris iris_virginica_list[MAX];
    Iris iris_versicolor_list[MAX];
    Iris iris_setosa_list[MAX];

    FILE *fp;
    fp = fopen("iris.data", "r");
    if (fp == NULL) {
        printf("Cannot open the file.");
        exit(0);
    }

    int i=0;
    while (fgets(line, MAX, fp) != NULL) {
        lists[i] = irisSprit(line);
        i++;
    }

    size = i;
    int iris_virginica_count = 0;
    int iris_versicolor_count = 0;
    int iris_setosa_count = 0;

    for(int j=0;j<i;j++){
        if(strcmp(lists[j].species,"Iris-virginica")==0){
            iris_virginica_list[iris_virginica_count] = lists[j];
            iris_virginica_count++;

        }else if(strcmp(lists[j].species,"Iris-versicolor")==0){
            iris_versicolor_list[iris_versicolor_count] = lists[j];
            iris_versicolor_count++;

        }else if(strcmp(lists[j].species,"Iris-setosa")==0){
            iris_setosa_list[iris_setosa_count] = lists[j];
            iris_setosa_count++;

        }
    }

    // 平均
    Iris aveVirginica = getAverage(iris_virginica_list, iris_virginica_count);
    Iris aveVersicolor = getAverage(iris_versicolor_list, iris_versicolor_count);
    Iris aveSetosa = getAverage(iris_setosa_list, iris_setosa_count);

    // 標準偏差
    Iris stdVirginica = getStandardDeviation(iris_virginica_list, iris_virginica_count);
    Iris stdVersicolor = getStandardDeviation(iris_versicolor_list, iris_versicolor_count);
    Iris stdSetosa = getStandardDeviation(iris_setosa_list, iris_setosa_count);

    // 判定
    Iris irisJudgment1 = {5.7,4.0,1.2,0.2,""};
    Iris irisJudgment2 = {5.9,2.9,4.2,1.5,""};
    Iris irisJudgment3 = {5.6,2.8,4.8,2.0,""};

    printf("judge\n");
    printf("sample1: ");
    printJudgement(lists,size ,irisJudgment1);
    printf("sample2: ");
    printJudgement(lists,size ,irisJudgment2);  
    printf("sample3: ");
    printJudgement(lists,size ,irisJudgment3);

    fclose(fp);

    return 0;
}