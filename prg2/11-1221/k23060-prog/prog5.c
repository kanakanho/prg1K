#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

// ランダムに並び替える関数
void shuffle(struct iris* irises, int n);

// forでprintする関数
void print_iris_array(struct iris* irises, int n);

int main(void) {
  // 宣言
  char line[50];
  FILE* fp;
  struct iris array_all[MAX_IRIS];
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
    array_all[count] = inputIris(line);
    count++;
  }

  // ファイルを閉じる
  fclose(fp);

  // 全て表示
  for (int i = 0; i < count; i++) {
    printf("[%d]-------------------\n", i + 1);
    print_iris(array_all[i]);
  }

  // ランダムに並び替え
  shuffle(array_all, count);

  // 4/5をlearnに、1/5をtestに
  int learnCount = count * 4 / 5;
  int testCount = count - learnCount;
  struct iris array_learn[learnCount];
  struct iris array_test[testCount];
  for (int i = 0; i < learnCount; i++) {
    array_learn[i] = array_all[i];
  }
  for (int i = 0; i < testCount; i++) {
    array_test[i] = array_all[i + learnCount];
  }

  // print
  printf("array_learn\n");
  print_iris_array(array_learn, learnCount);
  printf("array_test\n");
  print_iris_array(array_test, testCount);
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

void shuffle(struct iris* irises, int n) {
  int i, j;
  struct iris tmp;
  srand(time(NULL));

  for (i = n - 1; i >= 1; i--) {
    j = rand() % (i + 1);
    tmp = irises[j];
    irises[j] = irises[i];
    irises[i] = tmp;
  }
}

void print_iris_array(struct iris* irises, int n) {
  for (int i = 0; i < n; i++) {
    printf("[%d]-------------------\n", i + 1);
    print_iris(irises[i]);
  }
}
