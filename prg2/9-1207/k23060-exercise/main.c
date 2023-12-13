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
  for (int i = 0; i < count; i++) {
    for (int j = i + 1; j < count; j++) {
      if (earthquakes[i].loc.lat > earthquakes[j].loc.lat) {
        Earthquake tmp = earthquakes[i];
        earthquakes[i] = earthquakes[j];
        earthquakes[j] = tmp;
      }
    }
  }
  for (int i = 0; i < count; i++) {
    printEarthquake(earthquakes[i]);
  }

  // h2011_eq_lat.csvに書き込む ない時は作る
  fp = fopen("h2011_eq_lat.csv", "w");
  if (fp == NULL) {
    printf("ファイルを開けませんでした\n");
    return 0;
  }
  for (int i = 0; i < count; i++) {
    fprintf(fp, "%d,%d,%d,%f,%f,%s\n", earthquakes[i].date.year,
            earthquakes[i].date.month, earthquakes[i].date.day,
            earthquakes[i].loc.lat, earthquakes[i].loc.lon,
            earthquakes[i].scale);
  }
  fclose(fp);

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