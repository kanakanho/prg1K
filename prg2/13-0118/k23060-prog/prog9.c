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

  while (1) {
    char input[256];
    char type[2];
    char name[256] = "";
    double height = 0;
    double weight = 0;
    printf("Input number: ");
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%1s %255[^,],%lf,%lf", type, name, &height, &weight);
    if (strcmp(type, "q") == 0) {
      break;
    } else if (strcmp(type, "p") == 0) {
      print_mlist(root);
    } else if (strcmp(type, "d") == 0) {
      root = delete_melem(&root, name);
    } else if (strcmp(type, "a") == 0) {
      root = add_melem(&root, name, height, weight);
    } else {
      printf("無効な入力です\n");
    }
  }

  // メモリを解放する
  free_mlist(root);
  printf("メモリを解放しました\n");

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
