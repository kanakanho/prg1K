#include <stdio.h>
#include <sys/time.h>

int my_strlen(char *str);
void swap_str_ptr(char **str1, char **str2);
void sort_str_ptr(char **str1, char **str2);
void bubble_str_ptr(char **str, int size);

int main(void) {
  // 計測のための宣言
  unsigned int sec;
  int nsec;
  double d_sec;

  struct timespec start_time, end_time;
  // 計測開始
  clock_gettime(CLOCK_REALTIME, &start_time);

  // ソートする文字列の宣言
  char *list[] = {"hoge",   "abc",    "xy",        "fugagaga", "apple",
                  "banana", "cherry", "date",      "eggplant", "fig",
                  "grape",  "honey",  "ice cream", "juice",    "kiwi",
                  "lemon",  "melon",  "nut",       "orange",   "peach"};
  int size = sizeof(list) / sizeof(list[0]);

  printf("--------------------\n");
  printf("before\n");
  printf("--------------------\n");
  for (int i = 0; i < size; i++) {
    printf("%d : %s\n", i + 1, list[i]);
  }

  // ソート
  bubble_str_ptr(list, size);

  printf("--------------------\n");
  printf("after\n");
  printf("--------------------\n");
  for (int i = 0; i < size; i++) {
    printf("%d : %s\n", i + 1, list[i]);
  }

  // 計測終了
  clock_gettime(CLOCK_REALTIME, &end_time);

  // 時間を計算
  sec = end_time.tv_sec - start_time.tv_sec;
  nsec = end_time.tv_nsec - start_time.tv_nsec;

  d_sec = (double)sec + (double)nsec / (1000 * 1000 * 1000);
  
  printf("--------------------\n");
  printf("time:%f\n", d_sec);
  return 0;
}

int my_strlen(char *str) {
  int i = 0;
  while (str[i] != '\0') {
    i++;
  }
  return i;
}

void swap_str_ptr(char **str1, char **str2) {
  char *tmp = *str1;
  *str1 = *str2;
  *str2 = tmp;
}

void sort_str_ptr(char **str1, char **str2) {
  int size1 = my_strlen(*str1);
  int size2 = my_strlen(*str2);
  if (size1 > size2) {
    swap_str_ptr(str1, str2);
  }
}

void bubble_str_ptr(char **str, int size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - 1 - i; j++) {
      sort_str_ptr(&str[j], &str[j + 1]);
    }
  }
}