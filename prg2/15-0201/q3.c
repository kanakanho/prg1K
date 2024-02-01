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

  dispPassenger(root);
  freePassenger(root);

  // ファイルを閉じる
  fclose(fp);

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