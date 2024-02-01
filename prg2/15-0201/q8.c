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

int countSurvivedYoung(Passenger *root);
int countSurvivedMiddle(Passenger *root);
int countSurvivedOld(Passenger *root);

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
  int survivedYoung = countSurvivedYoung(root);
  int survivedMiddle = countSurvivedMiddle(root);
  int survivedOld = countSurvivedOld(root);
  double rateYoung = (double)survivedYoung / (double)survived;
  double rateMiddle = (double)survivedMiddle / (double)survived;
  double rateOld = (double)survivedOld / (double)survived;
  printf("子供生還割合：%f％, 大人生還割合：%f％, 老人生還割合：%f％\n",
         rateYoung * 100, rateMiddle * 100, rateOld * 100);

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

int countSurvivedYoung(Passenger *root) {
  Passenger *p = root;
  int count = 0;
  while (p != NULL) {
    if (p->survived == 1 && p->age < 20) {
      count++;
    }
    p = p->next;
  }
  return count;
}

int countSurvivedMiddle(Passenger *root) {
  Passenger *p = root;
  int count = 0;
  while (p != NULL) {
    if (p->survived == 1 && p->age >= 20 && p->age < 60) {
      count++;
    }
    p = p->next;
  }
  return count;
}

int countSurvivedOld(Passenger *root) {
  Passenger *p = root;
  int count = 0;
  while (p != NULL) {
    if (p->survived == 1 && p->age >= 60) {
      count++;
    }
    p = p->next;
  }
  return count;
}