#include <stdio.h>

int main(){

  const int n = 5;
  const int m = 5;


  // int mat1[n][m];
  // int mat2[m][n];
  // int result[n][n];

  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < n; j++) {
  //       for (int k = 0; k < m; k++) {
  //           result[i][j] += mat1[i][k] * mat2[k][j];
  //       }
  //   }
  // }

  int mat[n][m];
  int vec[m];
  int result[n];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      result[i] += mat[i][m]*vec[m];
    }
  }
  

  return 0;
}





