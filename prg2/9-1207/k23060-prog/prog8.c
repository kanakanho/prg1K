#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EQ 20000

typedef struct {
  int year;
  int month;
  int day;
} Date;
typedef struct {
  double lat;
  double lon;
} Location;
typedef struct {
  Date date;
  Location loc;
  char scale[2];
} Earthquake;

// 表示する関数
void printEarthquake(Earthquake i);

// 構造体に代入する関数
Earthquake inputEarthquake(char* line);

void countScale0311Over4s(Earthquake earthquakes[],
                          Earthquake earthquake0311Over4s[], int count) {}

int main(void) {
  // 宣言
  char line[50];
  FILE* fp;
  Earthquake earthquakes[MAX_EQ];
  int count = 0;

  // ファイルを開く
  fp = fopen("h2011_eq.csv", "r");
  if (fp == NULL) {
    printf("ファイルを開けませんでした\n");
    return 0;
  }

  // ファイルを読み込む
  while (fgets(line, 50, fp) != NULL) {
    if (*line && line[strlen(line) - 1] == '\n') {
      line[strlen(line) - 1] = '\0';
    }
    earthquakes[count] = inputEarthquake(line);
    count++;
  }

  // ファイルを閉じる
  fclose(fp);

  // 震度の回数をカウント
  Earthquake earthquake0311Over4s[MAX_EQ];
  int counter = 0;
  for (int i = 0; i < count; i++) {
    if (earthquakes[i].date.year == 2011 && earthquakes[i].date.month == 3 &&
        earthquakes[i].date.day == 11 &&
        (strcmp(earthquakes[i].scale, "4") == 0 ||
         strcmp(earthquakes[i].scale, "A") == 0 ||
         strcmp(earthquakes[i].scale, "B") == 0 ||
         strcmp(earthquakes[i].scale, "C") == 0 ||
         strcmp(earthquakes[i].scale, "D") == 0 ||
         strcmp(earthquakes[i].scale, "7") == 0)) {
      earthquake0311Over4s[counter] = earthquakes[i];
      counter++;
    }
  }

  // h2011_eq_0311.csvに書き込む
  FILE* fp2;
  fp2 = fopen("h2011_eq_0311.csv", "w");
  if (fp2 == NULL) {
    printf("ファイルを開けませんでした\n");
    return 0;
  }
  for (int i = 0; i < counter; i++) {
    fprintf(fp2, "%d,%d,%d,%f,%f,%s\n", earthquake0311Over4s[i].date.year,
            earthquake0311Over4s[i].date.month,
            earthquake0311Over4s[i].date.day, earthquake0311Over4s[i].loc.lat,
            earthquake0311Over4s[i].loc.lon, earthquake0311Over4s[i].scale);
  }
  fclose(fp2);
  return 0;
}

void printEarthquake(Earthquake i) {
  printf("year : %d\n", i.date.year);
  printf("month: %d\n", i.date.month);
  printf("day  : %d\n", i.date.day);
  printf("lat  : %f\n", i.loc.lat);
  printf("lon  : %f\n", i.loc.lon);
  printf("scale: %s\n", i.scale);
}

Earthquake inputEarthquake(char* line) {
  // 宣言
  char* tmp;
  char* tokens[6];
  int i = 0;
  int type = 0;
  tmp = strtok(line, ",");
  Earthquake earthquakes;

  // 構造体に代入
  while (tmp != NULL && i < 6) {
    tokens[i] = tmp;
    switch (type) {
      case 0:
        earthquakes.date.year = atoi(tokens[i]);
        break;
      case 1:
        earthquakes.date.month = atoi(tokens[i]);
        break;
      case 2:
        earthquakes.date.day = atoi(tokens[i]);
        break;
      case 3:
        earthquakes.loc.lat = atof(tokens[i]);
        break;
      case 4:
        earthquakes.loc.lon = atof(tokens[i]);
        break;
      case 5:
        strcpy(earthquakes.scale, tokens[i]);
        break;
      default:
        break;
    }
    i++;
    tmp = strtok(NULL, ",");
    type++;
  }
  return earthquakes;
}