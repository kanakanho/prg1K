#include <stdio.h>
#include <stdlib.h>

typedef struct elem {
  int num;            // データ部
  struct elem *next;  // ポインタ部
} Elem;

void print_list(Elem *root);
Elem *add_elem(Elem **root, int num);
void free_list(Elem *root);
Elem *delete_elem(Elem *root, int delnum);

    int main(void) {
  Elem *root = NULL;
  for (int i = 1; i < 10; i++) {
    root = add_elem(&root, i);
  }
  printf("初期値\n");
  print_list(root);

  int shift_num = 1;
  printf("%dを削除します\n", shift_num);
  root = delete_elem(root, shift_num);

  printf("削除後\n");
  print_list(root);

  free_list(root);
  printf("メモリを解放しました\n");
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
  // 次の要素とnumを比較する
  if (*root == NULL || (*root)->num >= p->num) {
    p->next = *root;
    *root = p;
  } else {
    Elem *current = *root;
    while (current->next != NULL && current->next->num < p->num) {
      current = current->next;
    }
    p->next = current->next;
    current->next = p;
  }
  // 新しいrootのアドレスを返す
  return *root;
}

void free_list(Elem *root) {
  // 全ての要素を解放する
  Elem *p = root;
  while (p != NULL) {
    Elem *tmp = p->next;
    free(p);
    p = tmp;
  }
}

Elem *delete_elem(Elem *root, int delnum) {
  Elem *p = root;
  Elem *prev = NULL;
  // 最初の要素を削除する場合
  if (p != NULL && p->num == delnum) {
    root = p->next;
    free(p);
    return root;
  }
  // 最初の要素以外を削除する場合
  while (p != NULL) {
    if (p->num == delnum) {
      if (prev != NULL) {
        prev->next = p->next;
      }
      Elem *tmp = p->next;
      free(p);
      return root;
    }
    prev = p;
    p = p->next;
  }
  return root;
}