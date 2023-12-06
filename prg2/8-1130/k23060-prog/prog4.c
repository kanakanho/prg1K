#include <stdio.h>
#include <string.h>

struct iris {
  double sepal_length;
  double sepal_width;
  double petal_length;
  double petal_width;
  char class[16];
};

void print_iris(struct iris i) {
  printf("sepal_length: %f\n", i.sepal_length);
  printf("sepal_width: %f\n", i.sepal_width);
  printf("petal_length: %f\n", i.petal_length);
  printf("petal_width: %f\n", i.petal_width);
  printf("class: %s\n", i.class);
}

int countConma(char* line) {
  int count = 0;
  int i = 0;
  while (line[i] != '\0') {
    if (line[i] == ',') {
      count++;
    }
    i++;
  }
  return count;
}

int main(void) {
  char line[50] = "5.7,2.9,4.2,1.3,Iris-versicolor\n";
  char* tmp;
  char* tokens[5];
  int i = 0;
  int count = countConma(line);

  tmp = strtok(line, ",");
  while (tmp != NULL) {
    tokens[i] = tmp;
    if (i == count) {
      tokens[i][strlen(tokens[i]) - 1] = '\0';
    }
    printf("%s\n", tokens[i]);
    i++;
    tmp = strtok(NULL, ",");
  }

  return 0;
}