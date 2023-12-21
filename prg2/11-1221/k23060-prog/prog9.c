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

// create array learn and test
void createLearnAndTest(struct iris* irises, int n, int setOneFifth,
                        struct iris array_learn[], struct iris array_test[]);

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

// 混同行列を描画（int）
void printConfusionMatrix(int confusionMatrix[3][3]);

// 混同行列を描画（double）
void printConfusionMatrixDouble(double confusionMatrix[3][3]);

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
  // セットする場所を決める（1~5）
  for (int setOneFifth = 0; setOneFifth < 5; setOneFifth++) {
    int learnCount = count * 4 / 5;
    int testCount = count - learnCount;
    struct iris array_learn[learnCount];
    struct iris array_test[testCount];

    createLearnAndTest(array_all, count, setOneFifth, array_learn, array_test);

    // 平均を求める
    for (int i = 0; i < 3; i++) {
      average(array_learn, classNames[i], count / 5 * 4, averages[i]);
    }

    // 標準偏差を求める
    for (int i = 0; i < 3; i++) {
      standardDeviation(array_learn, classNames[i], count / 5 * 4,
                        standardDeviations[i], averages[i]);
    }

    // 混同行列用の配列
    //            | Setosa | Verginica | versicolor
    // Setosa     |
    // Verginica  |
    // versicolor |
    int confusionMatrix[3][3] = {0};

    // testを推定
    for (int i = 0; i < testCount; i++) {
      int minIndex = 0;
      double min = 100000000;
      for (int j = 0; j < 3; j++) {
        double tmp = 0;
        tmp += pow((array_test[i].sepal_length - averages[j][0]) /
                       standardDeviations[j][0],
                   2);
        tmp += pow((array_test[i].sepal_width - averages[j][1]) /
                       standardDeviations[j][1],
                   2);
        tmp += pow((array_test[i].petal_length - averages[j][2]) /
                       standardDeviations[j][2],
                   2);
        tmp += pow((array_test[i].petal_width - averages[j][3]) /
                       standardDeviations[j][3],
                   2);
        tmp = sqrt(tmp);
        if (tmp < min) {
          min = tmp;
          minIndex = j;
        }
      }

      // 混同行列を作成
      if (strcmp(array_test[i].class, "Iris-setosa") == 0) {
        if (strcmp(array_test[i].class, classNames[minIndex]) == 0) {
          confusionMatrix[0][0]++;
        } else if (strcmp(classNames[minIndex], "Iris-virginica") == 0) {
          confusionMatrix[0][1]++;
        } else if (strcmp(classNames[minIndex], "Iris-versicolor") == 0) {
          confusionMatrix[0][2]++;
        }
      } else if (strcmp(array_test[i].class, "Iris-virginica") == 0) {
        if (strcmp(array_test[i].class, classNames[minIndex]) == 0) {
          confusionMatrix[1][1]++;
        } else if (strcmp(classNames[minIndex], "Iris-setosa") == 0) {
          confusionMatrix[1][0]++;
        } else if (strcmp(classNames[minIndex], "Iris-versicolor") == 0) {
          confusionMatrix[1][2]++;
        }
      } else if (strcmp(array_test[i].class, "Iris-versicolor") == 0) {
        if (strcmp(array_test[i].class, classNames[minIndex]) == 0) {
          confusionMatrix[2][2]++;
        } else if (strcmp(classNames[minIndex], "Iris-setosa") == 0) {
          confusionMatrix[2][0]++;
        } else if (strcmp(classNames[minIndex], "Iris-virginica") == 0) {
          confusionMatrix[2][1]++;
        }
      }
    }

    double correctConfusionMatrix[3][3] = {0};
    // 正解の数を数える
    int correctSetosa = 0;
    int correctVirginica = 0;
    int correctVersicolor = 0;
    for (int i = 0; i < 3; i++) {
      correctSetosa += confusionMatrix[0][i];
      correctVirginica += confusionMatrix[1][i];
      correctVersicolor += confusionMatrix[2][i];
    }
    // 正解率を求める
    for (int i = 0; i < 3; i++) {
      if (correctSetosa == 0) {
        correctConfusionMatrix[0][i] = 0;
      } else {
        correctConfusionMatrix[0][i] =
            (double)confusionMatrix[0][i] / correctSetosa;
      }

      if (correctVirginica == 0) {
        correctConfusionMatrix[1][i] = 0;
      } else {
        correctConfusionMatrix[1][i] =
            (double)confusionMatrix[1][i] / correctVirginica;
      }

      if (correctVersicolor == 0) {
        correctConfusionMatrix[2][i] = 0;
      } else {
        correctConfusionMatrix[2][i] =
            (double)confusionMatrix[2][i] / correctVersicolor;
      }
    }

    // 表示
    printf("[k=%d]-------------------------------------------\n", setOneFifth);
    printf("混同行列（カウント）\n");
    printConfusionMatrix(confusionMatrix);
    printf("混同行列（割合）\n");
    printConfusionMatrixDouble(correctConfusionMatrix);
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

void createLearnAndTest(struct iris* irises, int n, int setOneFifth,
                        struct iris array_learn[], struct iris array_test[]) {
  // 宣言
  int oneFifth = n / 5;
  int learnCount = n / 5 * 4;
  int testCount = n - learnCount;

  struct iris oneFifthFirst[oneFifth];
  struct iris oneFifthSecond[oneFifth];
  struct iris oneFifthThird[oneFifth];
  struct iris oneFifthFourth[oneFifth];
  struct iris oneFifthFifth[oneFifth];

  // 1/5ずつに分ける
  for (int i = 0; i < n; i++) {
    if (i < oneFifth) {
      oneFifthFirst[i] = irises[i];
    } else if (i < oneFifth * 2) {
      oneFifthSecond[i - oneFifth] = irises[i];
    } else if (i < oneFifth * 3) {
      oneFifthThird[i - oneFifth * 2] = irises[i];
    } else if (i < oneFifth * 4) {
      oneFifthFourth[i - oneFifth * 3] = irises[i];
    } else {
      oneFifthFifth[i - oneFifth * 4] = irises[i];
    }
  }

  switch (setOneFifth) {
    case 1:
      // array_learnに1以外をセット
      for (int i = oneFifth; i < n; i++) {
        array_learn[i - oneFifth] = irises[i];
      }
      // array_testに1をセット
      for (int i = 0; i < oneFifth; i++) {
        array_test[i] = irises[i];
      }
      break;
    case 2:
      // array_learnに2以外をセット
      for (int i = 0; i < oneFifth; i++) {
        array_learn[i] = irises[i];
      }
      for (int i = oneFifth * 2; i < n; i++) {
        array_learn[i - oneFifth] = irises[i];
      }
      // array_testに2をセット
      for (int i = oneFifth; i < oneFifth * 2; i++) {
        array_test[i - oneFifth] = irises[i];
      }
      break;
    case 3:
      // array_learnに3以外をセット
      for (int i = 0; i < oneFifth * 2; i++) {
        array_learn[i] = irises[i];
      }
      for (int i = oneFifth * 3; i < n; i++) {
        array_learn[i - oneFifth] = irises[i];
      }
      // array_testに3をセット
      for (int i = oneFifth * 2; i < oneFifth * 3; i++) {
        array_test[i - oneFifth * 2] = irises[i];
      }
      break;
    case 4:
      // array_learnに4以外をセット
      for (int i = 0; i < oneFifth * 3; i++) {
        array_learn[i] = irises[i];
      }
      for (int i = oneFifth * 4; i < n; i++) {
        array_learn[i - oneFifth] = irises[i];
      }
      // array_testに4をセット
      for (int i = oneFifth * 3; i < oneFifth * 4; i++)
        array_test[i - oneFifth * 3] = irises[i];
      break;
    case 5:
      // array_learnに5以外をセット
      for (int i = 0; i < oneFifth * 4; i++) {
        array_learn[i] = irises[i];
      }
      // array_testに5をセット
      for (int i = oneFifth * 4; i < n; i++) {
        array_test[i - oneFifth * 4] = irises[i];
      }
      break;

    default:
      break;
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

// 混同行列を描画
void printConfusionMatrix(int confusionMatrix[3][3]) {
  printf("------------------------------------------------\n");
  printf("           | Setosa | Verginica | versicolor\n");
  printf("Setosa     | %d      | %d         | %d\n", confusionMatrix[0][0],
         confusionMatrix[0][1], confusionMatrix[0][2]);
  printf("Verginica  | %d      | %d         | %d\n", confusionMatrix[1][0],
         confusionMatrix[1][1], confusionMatrix[1][2]);
  printf("versicolor | %d      | %d         | %d\n", confusionMatrix[2][0],
         confusionMatrix[2][1], confusionMatrix[2][2]);
  printf("------------------------------------------------\n");
}

// 混同行列を描画
void printConfusionMatrixDouble(double confusionMatrix[3][3]) {
  printf("------------------------------------------------\n");
  printf("           | Setosa | Verginica | versicolor\n");
  printf("Setosa     | %.2f   | %.2f      | %.2f\n", confusionMatrix[0][0],
         confusionMatrix[0][1], confusionMatrix[0][2]);
  printf("Verginica  | %.2f   | %.2f      | %.2f\n", confusionMatrix[1][0],
         confusionMatrix[1][1], confusionMatrix[1][2]);
  printf("versicolor | %.2f   | %.2f      | %.2f\n", confusionMatrix[2][0],
         confusionMatrix[2][1], confusionMatrix[2][2]);
  printf("------------------------------------------------\n");
}