#include <stdio.h>
#include <stdlib.h>

typedef struct elem {
  int num;            // データ部
  struct elem *next;  // ポインタ部
} Elem;

void print_list(Elem *root);

Elem *add_elem(Elem **root, int num);

int main(void) {
  Elem *root = NULL;
  root = add_elem(&root, 10);
  root = add_elem(&root, 7);
  root = add_elem(&root, 4);
  print_list(root);
  return 0;
}

void print_list(Elem *root) {
  Elem *p = root;
  while (p != NULL) {
    printf("%d\n", p->num);

    p = p->next;
  }
}

Elem *add_elem(Elem **root, int num) {
  Elem *p = (Elem *)malloc(sizeof(Elem));
  p->num = num;
  p->next = *root;
  *root = p;
  return *root;
}