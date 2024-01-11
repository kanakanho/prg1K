#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
  while (1) {
    char input[10];
    char type[2];
    int num;
    printf("Input number: ");
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%1s%d", type, &num);
    if (strcmp(type, "q") == 0) {
      break;
    } else if (strcmp(type, "p") == 0) {
      print_list(root);
    } else if (strcmp(type, "d") == 0) {
      root = delete_elem(root, num);
    } else if (strcmp(type, "a") == 0) {
      add_elem(&root, num);
    } else {
      printf("無効な入力です\n");
    }
  }
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