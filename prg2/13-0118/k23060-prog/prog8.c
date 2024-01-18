#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct melem {
  char name[256];
  double height;
  double weight;
  struct melem *next;
} Melem;

void print_mlist(Melem *root);

Melem *add_melem(Melem **root, char *name, double height, double weight);

void free_mlist(Melem *root);

Melem *delete_melem(Melem **root, char *name);

int main(void) {
  Melem *root = NULL;
  char name[256];
  strcpy(name, "Aimi");
  root = add_melem(&root, name, 170, 60);
  strcpy(name, "Bell");
  root = add_melem(&root, name, 180, 70);
  strcpy(name, "Chad");
  root = add_melem(&root, name, 190, 80);

  printf("before delete\n");
  print_mlist(root);

  strcpy(name, "Bell");
  delete_melem(&root, name);

  printf("after delete\n");
  print_mlist(root);
  free_mlist(root);
  return 0;
}

void print_mlist(Melem *root) {
  Melem *p = root;
  while (p != NULL) {
    printf("%s %f %f\n", p->name, p->height, p->weight);

    p = p->next;
  }
}

Melem *add_melem(Melem **root, char *name, double height, double weight) {
  Melem *p = (Melem *)malloc(sizeof(Melem));
  strcpy(p->name, name);
  p->height = height;
  p->weight = weight;
  p->next = NULL;
  // name を 比較して、辞書順になるように挿入する
  if (*root == NULL) {
    *root = p;
  } else if (strcmp(name, (*root)->name) == 0) {
    // 同じ名前の人がいたら、height と weight を更新する
    (*root)->height = height;
    (*root)->weight = weight;
  } else if (strcmp(name, (*root)->name) < 0) {
    p->next = *root;
    *root = p;
  } else {
    Melem *current = *root;
    while (current->next != NULL && strcmp(current->next->name, name) < 0) {
      current = current->next;
    }
    p->next = current->next;
    current->next = p;
  }
  return *root;
}

void free_mlist(Melem *root) {
  Melem *p = root;
  while (p != NULL) {
    Melem *tmp = p->next;
    free(p);
    p = tmp;
  }
}

Melem *delete_melem(Melem **root, char *name) {
  Melem *p = *root;
  if (p == NULL) {
    return NULL;
  } else if (strcmp(p->name, name) == 0) {
    *root = p->next;
    free(p);
    return *root;
  } else {
    while (p->next != NULL && strcmp(p->next->name, name) != 0) {
      p = p->next;
    }
    if (p->next == NULL) {
      return NULL;
    } else {
      Melem *tmp = p->next;
      p->next = p->next->next;
      free(tmp);
      return p->next;
    }
  }
}