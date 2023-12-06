#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IRIS 150

struct iris {
  double sepal_length;
  double sepal_width;
  double petal_length;
  double petal_width;
  char class[16];
};

// 表示する関数
void print_iris(struct iris i);

// 構造体に代入する関数
struct iris inputIris(char* line);

// クラスごとの平均を求める関数
void average(struct iris irises[], char className[], int count,
             double averages[]);

int main(void) {
  // 宣言
  char line[50];
  FILE* fp;
  struct iris irises[MAX_IRIS];
  int count = 0;
  double averages[3][4];

  // ファイルを開く
  fp = fopen("iris.data", "r");
  if (fp == NULL) {
    printf("ファイルを開けませんでした\n");
    return 0;
  }

  // ファイルを読み込む
  while (fgets(line, 50, fp) != NULL) {
    if (*line && line[strlen(line) - 1] == '\n') {
      line[strlen(line) - 1] = 0;
    }
    irises[count] = inputIris(line);
    count++;
  }

  // ファイルを閉じる
  fclose(fp);

  // クラスの名前の一覧を作成
  char classNames[3][16];
  int classNamesCount = 0;
  for (int i = 0; i < count; i++) {
    int isExist = 0;
    for (int j = 0; j < classNamesCount; j++) {
      if (strcmp(irises[i].class, classNames[j]) == 0) {
        isExist = 1;
      }
    }
    if (isExist == 0) {
      strcpy(classNames[classNamesCount], irises[i].class);
      classNamesCount++;
    }
  }

  // 平均を求める
  for (int i = 0; i < 3; i++) {
    average(irises, classNames[i], count, averages[i]);
  }

  // 平均を表示
    for (int i = 0; i < 3; i++) {
        printf("[%s]---------\n", classNames[i]);
        printf("sepal_length: %f\n", averages[i][0]);
        printf("sepal_width: %f\n", averages[i][1]);
        printf("petal_length: %f\n", averages[i][2]);
        printf("petal_width: %f\n", averages[i][3]);
    }

  return 0;
}

void print_iris(struct iris i) {
  printf("sepal_length: %f\n", i.sepal_length);
  printf("sepal_width: %f\n", i.sepal_width);
  printf("petal_length: %f\n", i.petal_length);
  printf("petal_width: %f\n", i.petal_width);
  printf("class: %s\n", i.class);
}

struct iris inputIris(char* line) {
  // 宣言
  char* tmp;
  char* tokens[5];
  int i = 0;
  int type = 0;
  tmp = strtok(line, ",");
  struct iris iris;

  // 構造体に代入
  while (tmp != NULL) {
    tokens[i] = tmp;
    switch (type) {
      case 0:
        iris.sepal_length = atof(tokens[i]);
        break;
      case 1:
        iris.sepal_width = atof(tokens[i]);
        break;
      case 2:
        iris.petal_length = atof(tokens[i]);
        break;
      case 3:
        iris.petal_width = atof(tokens[i]);
        break;
      case 4:
        strcpy(iris.class, tokens[i]);
        break;
      default:
        break;
    }
    i++;
    tmp = strtok(NULL, ",");
    type++;
  }
  return iris;
}

void average(struct iris irises[], char className[], int count,
             double averages[]) {
  // 宣言
  double sepal_length = 0;
  double sepal_width = 0;
  double petal_length = 0;
  double petal_width = 0;
  int elements = 0;

  // 平均を求める
  for (int i = 0; i < count; i++) {
    if (strcmp(irises[i].class, className) == 0) {
      sepal_length += irises[i].sepal_length;
      sepal_width += irises[i].sepal_width;
      petal_length += irises[i].petal_length;
      petal_width += irises[i].petal_width;
      elements++;
    }
  }
  averages[0] = sepal_length / elements;
  averages[1] = sepal_width / elements;
  averages[2] = petal_length / elements;
  averages[3] = petal_width / elements;
}