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

typedef struct {
  double lat;
  int count;
} CountLocation;

// 表示する関数
void printLatCount(CountLocation i);

// 構造体に代入する関数
Earthquake inputEarthquake(char* line);

// 緯度でソート
void sortLat(Earthquake* earthquakes, int count);

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

  // 緯度でソート
  sortLat(earthquakes, count);

  // 2°毎の地震の数を数える
  CountLocation countLocation[MAX_EQ];
  double tmpLat = earthquakes[0].loc.lat;
  countLocation[0].lat = tmpLat;
  int tmpNum = 0;
  for (int i = 0; i < count; i++) {
    // 2°毎の地震の数を数える
    if (earthquakes[i].loc.lat - tmpLat > 2) {
      tmpNum++;
      tmpLat = earthquakes[i].loc.lat;
      countLocation[tmpNum].lat = tmpLat;
    }
    countLocation[tmpNum].count++;
  }

  for (int i = 0; i < 1000; i++) {
    printLatCount(countLocation[i]);
  }

  return 0;
}

void printLatCount(CountLocation i) {
  // からのときは表示しない
  if (i.lat == 0) {
    return;
  }
  printf("lat: %f,count: %d\n", i.lat, i.count);
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

void sortLat(Earthquake* earthquakes, int count) {
  Earthquake tmp;
  for (int i = 0; i < count; i++) {
    for (int j = count - 1; j > i; j--) {
      if (earthquakes[j].loc.lat < earthquakes[j - 1].loc.lat) {
        tmp = earthquakes[j];
        earthquakes[j] = earthquakes[j - 1];
        earthquakes[j - 1] = tmp;
      }
    }
  }
}