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

// 性別で数える関数
int countFemale(Passenger *root);
int countMale(Passenger *root);

// 生存者数を数える関数
int countSurvived(Passenger *root);

int countSurvivedMale(Passenger *root);
int countSurvivedFemale(Passenger *root);

// 死亡者数を数える関数
int countDied(Passenger *root);

int countDiedMale(Passenger *root);
int countDiedFemale(Passenger *root);

int main(void) {
  Passenger *root = NULL;
  char line[256];
  FILE *fp;

  // 全体の人数を数える
  int count = 0;

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
    count++;
  }

  // 男性、女性を数える
  int numMale = countMale(root);
  int numFemale = countFemale(root);

  // 生存者、死亡者を数える
  int survived = countSurvived(root);
  int survivedMale = countSurvivedMale(root);
  int survivedFemale = countSurvivedFemale(root);
  double survivedMaleRate = (double)survivedMale / (double)numMale * 100;
  double survivedFemaleRate = (double)survivedFemale / (double)numFemale * 100;

  // 注：男性なら男性、女性なら女性の生き残った割合を示す
  printf("男性生還割合：%f％, 女性生還割合：%f％\n", survivedMaleRate,
         survivedFemaleRate);

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

int countFemale(Passenger *root) {
  Passenger *p = root;
  int count = 0;
  while (p != NULL) {
    if (strcmp(p->sex, "female") == 0) {
      count++;
    }
    p = p->next;
  }
  return count;
}

int countMale(Passenger *root) {
  Passenger *p = root;
  int count = 0;
  while (p != NULL) {
    if (strcmp(p->sex, "male") == 0) {
      count++;
    }
    p = p->next;
  }
  return count;
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

int countSurvivedMale(Passenger *root) {
  Passenger *p = root;
  int count = 0;
  while (p != NULL) {
    if (p->survived == 1 && strcmp(p->sex, "male") == 0) {
      count++;
    }
    p = p->next;
  }
  return count;
}

int countSurvivedFemale(Passenger *root) {
  Passenger *p = root;
  int count = 0;
  while (p != NULL) {
    if (p->survived == 1 && strcmp(p->sex, "female") == 0) {
      count++;
    }
    p = p->next;
  }
  return count;
}

int countDied(Passenger *root) {
  Passenger *p = root;
  int count = 0;
  while (p != NULL) {
    if (p->survived == 0) {
      count++;
    }
    p = p->next;
  }
  return count;
}

int countDiedMale(Passenger *root) {
  Passenger *p = root;
  int count = 0;
  while (p != NULL) {
    if (p->survived == 0 && strcmp(p->sex, "male") == 0) {
      count++;
    }
    p = p->next;
  }
  return count;
}

int countDiedFemale(Passenger *root) {
  Passenger *p = root;
  int count = 0;
  while (p != NULL) {
    if (p->survived == 0 && strcmp(p->sex, "female") == 0) {
      count++;
    }
    p = p->next;
  }
  return count;
}
