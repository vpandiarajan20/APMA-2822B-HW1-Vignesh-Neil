#include <stdio.h>
#include <iostream>
#include <vector>
#include <random>

int main(int argc, char* argv[]) {
  if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <n> <m>" << std::endl;
        return 1;  // Return an error code indicating incorrect usage
  }

    // Convert the command-line arguments to integers
    int num1 = std::atoi(argv[1]);
    int num2 = std::atoi(argv[2]);

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

  // double mat[n][m];
  // double vec[m];
  // double result[n];

  // std::random_device rd;
  // std::mt19937 gen(rd());  // Mersenne Twister 19937 generator
  // std::uniform_real_distribution<double> distribution(1.0, 100.0);

  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < m; j++) {
  //       mat[i][j] = distribution(gen);  // Generate a random double value and store it in the matrix
  //   }
  // }
  // for (int i = 0; i < m; i++) {
  //   vec[i] = distribution(gen);
  // }

  

  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < m; j++) {
  //     result[i] += mat[i][m]*vec[m];
  //   }
  // }
  // return 0;




  // non-contiguous memory alloc
  // double **mat;
  // mat = new double*[n];
  // for (int i = 0; i < n; i++) {
  //   mat[i] = new double[m];
  // }

  // double *vec;
  // vec = new double[m];

  // for (int i = 0; i < n; i++) {
  //   delete(mat[i]);
  // }
  // delete[] mat;


  // contiguous mem
  // double **mat;
  // mat = new double*[n];
  // mat[0] = new double[n*m];
  // double *vec;
  // vec = new double[m];


  // for (int i = 1; i < n; i++) {
  //   mat[i] = mat[0] + i * m;
  // }
  // delete[] mat[0];
}





