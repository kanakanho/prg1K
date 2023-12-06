#include <stdio.h>

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

int main(void) {
  struct iris iris1 = {6.7, 3.0, 5.2, 2.3, ":Iris-virginica"};
  struct iris iris2 = {7.0, 3.2, 4.7, 1.4, "Iris-versicolor"};

  print_iris(iris1);
  printf("--------------------\n");
  print_iris(iris2);

  return 0;
}