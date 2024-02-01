#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Passenger {
  char class[256];
  double age;
  char sex[10];
  int survived;
  struct Passenger *next;
} Passenger;

// 構造体に追加する関数
Passenger *addPassenger(Passenger **root, char *class, double age, char *sex,
                        int survived);

// 構造体の内容を表示する関数
void dispPassenger(Passenger *root);

// メモリを解放する関数
void freePassenger(Passenger *root);

// 生存者数を数える関数
int countSurvived(Passenger *root);

int countSurvivedFirstClass(Passenger *root);
int countSurvivedSecondClass(Passenger *root);
int countSurvivedThirdClass(Passenger *root);

int main(void) {
  Passenger *root = NULL;
  char line[256];
  FILE *fp;

  // ファイルを開く
  fp = fopen("titanic.csv", "r");
  if (fp == NULL) {
    printf("ファイルを開けませんでした\n");
    return 1;
  }

  char input[256];
  // ファイルを読み込む
  while (fgets(input, sizeof(input), fp) != NULL) {
    char class[256];
    double age;
    char sex[10];
    int survived;
    sscanf(input, "%255[^,],%lf,%9[^,],%d\n", class, &age, sex, &survived);
    root = addPassenger(&root, class, age, sex, survived);
  }

  // 生存者、死亡者を数える
  int survived = countSurvived(root);
  int survivedFirstClass = countSurvivedFirstClass(root);
  int survivedSecondClass = countSurvivedSecondClass(root);
  int survivedThirdClass = countSurvivedThirdClass(root);
  double survivedFirstClassRate =
      (double)survivedFirstClass / (double)survived * 100;
  double survivedSecondClassRate =
      (double)survivedSecondClass / (double)survived * 100;
  double survivedThirdClassRate =
      (double)survivedThirdClass / (double)survived * 100;
  printf("1st 生還割合：%f％, 2nd 生還割合：%f％, 3rd 生還割合：%f％\n",
         survivedFirstClassRate, survivedSecondClassRate,
         survivedThirdClassRate);

  // 終了処理
  // ファイルを閉じる
  fclose(fp);
  // メモリ解放
  freePassenger(root);

  return 0;
}

Passenger *addPassenger(Passenger **root, char *class, double age, char *sex,
                        int survived) {
  Passenger *p = (Passenger *)malloc(sizeof(Passenger));
  strcpy(p->class, class);
  p->age = age;
  strcpy(p->sex, sex);
  p->survived = survived;
  p->next = *root;
  *root = p;
  return *root;
}

void dispPassenger(Passenger *root) {
  Passenger *p = root;
  while (p != NULL) {
    printf("乗船クラス：%s, 年齢：%f, 性別：%s, 生還：%d\n", p->class, p->age,
           p->sex, p->survived);
    p = p->next;
  }
}

void freePassenger(Passenger *root) {
  Passenger *p = root;
  while (p != NULL) {
    Passenger *tmp = p->next;
    free(p);
    p = tmp;
  }
}

int countSurvived(Passenger *root) {
  Passenger *p = root;
  int count = 0;
  while (p != NULL) {
    if (p->survived == 1) {
      count++;
    }
    p = p->next;
  }
  return count;
}

int countSurvivedFirstClass(Passenger *root) {
  Passenger *p = root;
  int count = 0;
  while (p != NULL) {
    if (p->survived == 1 && strcmp(p->class, "1st") == 0) {
      count++;
    }
    p = p->next;
  }
  return count;
}

int countSurvivedSecondClass(Passenger *root) {
  Passenger *p = root;
  int count = 0;
  while (p != NULL) {
    if (p->survived == 1 && strcmp(p->class, "2nd") == 0) {
      count++;
    }
    p = p->next;
  }
  return count;
}

int countSurvivedThirdClass(Passenger *root) {
  Passenger *p = root;
  int count = 0;
  while (p != NULL) {
    if (p->survived == 1 && strcmp(p->class, "3rd") == 0) {
      count++;
    }
    p = p->next;
  }
  return count;
}