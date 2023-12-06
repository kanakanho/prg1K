#include <stdio.h>

struct student {
  char name[64];
  int age;
  char id[8];
  int degree;
};

void print_student(struct student s) {
  printf("name: %s\n", s.name);
  printf("age: %d\n", s.age);
  printf("id: %s\n", s.id);
  printf("grade: %d\n", s.degree);
}

int main(void) {
  struct student s1 = {"Shibata Seiken", 19, "k23060", 1};
  struct student s2 = {"Makino Haruto", 19, "k22120", 2};
  struct student s3 = {"Mizutani Ysei", 21, "k21116", 3};

  print_student(s1);
  printf("--------------------\n");
  print_student(s2);
  printf("--------------------\n");
  print_student(s3);

  return 0;
};