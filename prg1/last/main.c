#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>  // srand関数を使用するために必要なヘッダファイルを追加

int main(int argc, const char* argv[]) {
  int counter = 0;
  int isFinished = 0;
  char text[10] = "";  // 文字列を格納するための十分な大きさの配列
  // 0で初期化された4*4の配列を宣言
  int matrix[4][4] = {{0}};
  int tmp_matrix[4][4] = {{0}};

  srand(time(0));  // 乱数の初期化

  // matrixの空いているマスに2を2個ランダムで入れる
  for (int i = 0; i < 2; i++) {
    while (1) {
      int x = rand() % 4;
      int y = rand() % 4;
      if (matrix[x][y] == 0) {
        matrix[x][y] = 2;
        break;
      }
    }
  }

  // break まで繰り返す
  while (1) {
    // matrixの中身を表示
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {  // jの範囲を修正
        printf("%d ", matrix[i][j]);
      }
      printf("\n");
    }
    // matrixの中で”2048"を探す
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {  // jの範囲を修正
        if (matrix[i][j] == 2048) {
          isFinished = 1;
        }
      }
    }
    if (isFinished == 1) {
      printf("Game Clear!\n");
      return 0;
    }
    // matrixの中で隣り合う同じ数字がないときcounterに1を格納する
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 3; j++) {
        if (matrix[i][j] == matrix[i][j + 1] && matrix[i][j] >= 2) {
          counter = 0;
          break;
        }
      }
      if (counter == 0) {
        break;
      }
    }
    if (counter == 1) {
      printf("Game Over!\n");
      return 0;
    }
    // matrixの空いているマスに2をランダムで入れる
    while (1) {
      int x = rand() % 4;
      int y = rand() % 4;
      if (matrix[x][y] == 0) {
        matrix[x][y] = 2;
        break;
      }
    }
    // top left bottom rightの入力
    printf("top or left or bottom or right: ");
    scanf("%s", text);  // & を削除することができます。

    if (strcmp(text, "top") == 0) {  // 文字列の比較にはstrcmpを使用
      for (int i = 0; i < 3; i++) {  // iの範囲を修正
        if (matrix[i][0] == matrix[i + 1][0]) {
          tmp_matrix[i][0] = matrix[i][0] + matrix[i + 1][0];
        }
      }
    }
    if (strcmp(text, "left") == 0) {
      // matrix[0][0]とmatrix[0][1]が同じ値のとき足してtmp_matrix[0][0]に格納するこれを4回繰り返す
      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {  // jの範囲を修正
          if (matrix[i][j] == matrix[i][j + 1]) {
            tmp_matrix[i][j] = matrix[i][j] + matrix[i][j + 1];
          }
        }
      }
    }
    if (strcmp(text, "bottom") == 0) {
      // matrix[0][0]とmatrix[0][1]が同じ値のとき足してtmp_matrix[1][0]に格納すこれを4回繰り返す
      for (int i = 0; i < 3; i++) {  // iの範囲を修正
        if (matrix[i][0] == matrix[i + 1][0]) {
          tmp_matrix[i + 1][0] = matrix[i][0] + matrix[i + 1][0];
        }
      }
    }
    if (strcmp(text, "right") == 0) {
      // matrix[0][0]とmatrix[0][1]が同じ値のとき足してtmp_matrix[0][1]に格納すこれを4回繰り返す
      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {  // jの範囲を修正
          if (matrix[i][j] == matrix[i][j + 1]) {
            tmp_matrix[i][j + 1] = matrix[i][j] + matrix[i][j + 1];
          }
        }
      }
    }
    // tmp_matrixをmatrixに格納する
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {  // jの範囲を修正
        matrix[i][j] = tmp_matrix[i][j];
      }
    }
  }
}
