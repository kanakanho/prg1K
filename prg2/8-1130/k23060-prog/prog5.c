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

int main(void) {
  // 宣言
  char line[50];
  FILE* fp;
  struct iris irises[MAX_IRIS];
  int count = 0;

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

  // 全て表示
  for (int i = 0; i < count; i++) {
    printf("[%d]-------------------\n", i + 1);
    print_iris(irises[i]);
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