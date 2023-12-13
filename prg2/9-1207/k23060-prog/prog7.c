#include <math.h>
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

void countScale(Earthquake earthquakes[], int count, int scaleCount[]);

int GetStandardDeviation(Earthquake earthquakes[], int count,
                         int averageScales);

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
  char scales[9][4] = {"1", "2", "3", "4", "5-", "5+", "6-", "6+", "7"};
  int scaleCount[9] = {0};
  double averageScales;
  int standardDeviation;
  countScale(earthquakes, count, scaleCount);
  averageScales = (double)count / (double)365;
  standardDeviation =
      GetStandardDeviation(earthquakes, count, averageScales);

  // 表示
  printf("1日あたりの平均 : %f\n", averageScales);
  // printf("標準偏差 : %d\n", standardDeviation);
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

void countScale(Earthquake earthquakes[], int count, int scaleCount[]) {
  for (int i = 0; i < count; i++) {
    if (strcmp(earthquakes[i].scale, "1") == 0) {
      scaleCount[0]++;
    } else if (strcmp(earthquakes[i].scale, "2") == 0) {
      scaleCount[1]++;
    } else if (strcmp(earthquakes[i].scale, "3") == 0) {
      scaleCount[2]++;
    } else if (strcmp(earthquakes[i].scale, "4") == 0) {
      scaleCount[3]++;
    } else if (strcmp(earthquakes[i].scale, "A") == 0) {
      scaleCount[4]++;
    } else if (strcmp(earthquakes[i].scale, "B") == 0) {
      scaleCount[5]++;
    } else if (strcmp(earthquakes[i].scale, "C") == 0) {
      scaleCount[6]++;
    } else if (strcmp(earthquakes[i].scale, "D") == 0) {
      scaleCount[7]++;
    } else if (strcmp(earthquakes[i].scale, "7") == 0) {
      scaleCount[8]++;
    }
  }
}

int GetStandardDeviation(Earthquake earthquakes[], int count,
                         int averageScales) {
  int sum = 0;
  int sums[365] = {0};
  Date tmp;
  int i = 0;
  Date today;
  // 毎日の地震の数を求める
  do {
    today = earthquakes[i].date;
    if (tmp.year == today.year && tmp.month == today.month &&
        tmp.day == today.day) {
      i++;
      continue;
    }
    for (int j = 0; j < count; j++) {
      if (earthquakes[j].date.year == today.year &&
          earthquakes[j].date.month == today.month &&
          earthquakes[j].date.day == today.day) {
        sum++;
      }
    }
    sums[i] = sum;
    tmp = today;
  } while (sums[364] != 0);

  // 標準偏差を求める
  for (int i = 0; i < 365; i++) {
    sum += pow(sums[i] - averageScales, 2);
  }
    
  int standardDeviation = sqrt(sum / 365);
  return standardDeviation;
}