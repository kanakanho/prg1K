//
//  11_challenge1_k23060.c
//
//
//  Created by k23060kk on 2023/06/29.
//

#include <stdio.h>

int main(int argc, const char* argv[]) {
  int index = 0;
  char searchTerm[13] = {'\0'};
  char paragraph[] =
      "we hold these truths to be self-evident, that all men are created "
      "equal, that they are endowed by their creator with certain unalienable "
      "rights, that among these are life, liberty and the pursuit of "
      "happiness.";
  // 入力
  printf("input: ");
  scanf("%s", searchTerm);
  // 検索
  if (searchTerm[12] != '\0') {
    printf("indexOf: -1\n");
    return 0;
  }
  // 検索
  for (int i = 0; i < sizeof(paragraph); i++) {
    if (paragraph[i] != searchTerm[0]) {
      continue;
    }
  // 検索
    index = i;
    for (int j = 0; j < sizeof(searchTerm); j++) {
      if (searchTerm[j] == '\0'){
        break;
        }
      if (paragraph[i + j] != searchTerm[j]) {
        index = -1;
        break;
      }
    }
    if (index != -1) {
      break;
  }
  // 出力
  printf("indexOf: %d\n", index);
  return 0;
}