#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EQ 150

struct earthquake {
  int year;
  int month;
  int day;
  double lat;
  double lon;
  char scale[2];
};

// 表示する関数
void printEarthquake(struct earthquake i);

// 構造体に代入する関数
struct earthquake inputEarthquake(char* line);

int main(void) {
  // 宣言
  struct earthquake earthquakes[MAX_EQ];
  int count = 0;

  char line[] = "2011,1,3,38.929000,140.609333,1";
  earthquakes[count] = inputEarthquake(line);
  count++;

  // 全て表示
  for (int i = 0; i < count; i++) {
    printf("[地震情報%d]---------\n", i + 1);
    printEarthquake(earthquakes[i]);
  }

  return 0;
}

void printEarthquake(struct earthquake i) {
  printf("year : %d\n", i.year);
  printf("month: %d\n", i.month);
  printf("day  : %d\n", i.day);
  printf("lat  : %f\n", i.lat);
  printf("lon  : %f\n", i.lon);
  printf("scale: %s\n", i.scale);
}

struct earthquake inputEarthquake(char* line) {
  // 宣言
  char* tmp;
  char* tokens[6];
  int i = 0;
  int type = 0;
  tmp = strtok(line, ",");
  struct earthquake earthquakes;

  // 構造体に代入
  while (tmp != NULL) {
    tokens[i] = tmp;
    switch (type) {
      case 0:
        earthquakes.year = atoi(tokens[i]);
        break;
      case 1:
        earthquakes.month = atoi(tokens[i]);
        break;
      case 2:
        earthquakes.day = atoi(tokens[i]);
        break;
      case 3:
        earthquakes.lat = atof(tokens[i]);
        break;
      case 4:
        earthquakes.lon = atof(tokens[i]);
        break;
      case 5:
        strcpy(earthquakes.scale, tokens[i]);
      default:
        break;
    }
    i++;
    tmp = strtok(NULL, ",");
    type++;
  }
  return earthquakes;
}