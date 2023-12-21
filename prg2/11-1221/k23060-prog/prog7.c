#include <math.h>
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

// クラスごとの平均を求める関数
void average(struct iris irises[], char className[], int count,
             double averages[]);

// 偏差を求める
double deviation(double data, double average);

// 分散を求める
double variance(double deviations[], int count);

// クラスごとの標準偏差を求める関数
void standardDeviation(struct iris irises[], char className[], int count,
                       double standardDeviations[], double averages[]);

int main(void) {
  // 宣言
  char line[50];
  FILE* fp;
  struct iris array_all[MAX_IRIS];
  int count = 0;
  double averages[3][4];
  double standardDeviations[3][4];

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

  // クラスの名前の一覧を作成
  char classNames[3][16];
  int classNamesCount = 0;
  for (int i = 0; i < count; i++) {
    int isExist = 0;
    for (int j = 0; j < classNamesCount; j++) {
      if (strcmp(array_all[i].class, classNames[j]) == 0) {
        isExist = 1;
      }
    }
    if (isExist == 0) {
      strcpy(classNames[classNamesCount], array_all[i].class);
      classNamesCount++;
    }
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

  // 平均を求める
  for (int i = 0; i < 3; i++) {
    average(array_learn, classNames[i], count / 5 * 4, averages[i]);
  }

  // 標準偏差を求める
  for (int i = 0; i < 3; i++) {
    standardDeviation(array_learn, classNames[i], count / 5 * 4,
                      standardDeviations[i], averages[i]);
  }

  // testを推定
  int isCorrect[count];
  for (int i = 0; i < testCount; i++) {
    int minIndex = 0;
    double min = 100000000;
    for (int j = 0; j < 3; j++) {
      double tmp = 0;
      tmp += pow(
          (array_test[i].sepal_length - averages[j][0]) / standardDeviations[j][0],
          2);
      tmp += pow(
          (array_test[i].sepal_width - averages[j][1]) / standardDeviations[j][1], 2);
      tmp += pow(
          (array_test[i].petal_length - averages[j][2]) / standardDeviations[j][2],
          2);
      tmp += pow(
          (array_test[i].petal_width - averages[j][3]) / standardDeviations[j][3], 2);
      tmp = sqrt(tmp);
      if (tmp < min) {
        min = tmp;
        minIndex = j;
      }
    }
    if (strcmp(array_test[i].class, classNames[minIndex]) == 0) {
      isCorrect[i] = 1;
    } else {
      isCorrect[i] = 0;
    }
    printf("%s%d , Correct: %s , 推定: %s , 正解: %s\n", i < 10 ? " " : "", i,
           isCorrect[i] ? "true " : "false", array_test[i].class, array_all[i].class);
  }
  
  // 正解率を求める
  int correctCount = 0;
  for (int i = 0; i < testCount; i++) {
    if (isCorrect[i] == 1) {
      correctCount++;
    }
  }
  printf("正解率: %f\n", (double)correctCount / testCount);
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

// 偏差を求める
double deviation(double data, double average) {
  double deviation = data - average;
  return deviation;
}

// 分散を求める
double variance(double deviations[], int count) {
  double variance = 0;
  for (int i = 0; i < count; i++) {
    variance += deviations[i] * deviations[i];
  }
  variance /= count;
  return variance;
}

void standardDeviation(struct iris irises[], char className[], int count,
                       double standardDeviations[], double averages[]) {
  // 宣言
  double sepal_lengthDeviations[MAX_IRIS];
  double sepal_widthDeviations[MAX_IRIS];
  double petal_lengthDeviations[MAX_IRIS];
  double petal_widthDeviations[MAX_IRIS];
  int sepal_lengthDeviationsCount = 0;
  int sepal_widthDeviationsCount = 0;
  int petal_lengthDeviationsCount = 0;
  int petal_widthDeviationsCount = 0;

  // 偏差を求める
  for (int i = 0; i < count; i++) {
    if (strcmp(irises[i].class, className) == 0) {
      sepal_lengthDeviations[sepal_lengthDeviationsCount] =
          deviation(irises[i].sepal_length, averages[0]);
      sepal_lengthDeviationsCount++;
      sepal_widthDeviations[sepal_widthDeviationsCount] =
          deviation(irises[i].sepal_width, averages[1]);
      sepal_widthDeviationsCount++;
      petal_lengthDeviations[petal_lengthDeviationsCount] =
          deviation(irises[i].petal_length, averages[2]);
      petal_lengthDeviationsCount++;
      petal_widthDeviations[petal_widthDeviationsCount] =
          deviation(irises[i].petal_width, averages[3]);
      petal_widthDeviationsCount++;
    }
  }

  // 分散を求める
  standardDeviations[0] =
      variance(sepal_lengthDeviations, sepal_lengthDeviationsCount);
  standardDeviations[1] =
      variance(sepal_widthDeviations, sepal_widthDeviationsCount);
  standardDeviations[2] =
      variance(petal_lengthDeviations, petal_lengthDeviationsCount);
  standardDeviations[3] =
      variance(petal_widthDeviations, petal_widthDeviationsCount);

  // 標準偏差を求める
  standardDeviations[0] = sqrt(standardDeviations[0]);
  standardDeviations[1] = sqrt(standardDeviations[1]);
  standardDeviations[2] = sqrt(standardDeviations[2]);
  standardDeviations[3] = sqrt(standardDeviations[3]);
}