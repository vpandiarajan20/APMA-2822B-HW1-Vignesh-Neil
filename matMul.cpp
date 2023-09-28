#include <stdio.h>
#include <iostream>
#include <vector>
#include <random>
#include <sys/time.h>


int main(int argc, char* argv[]) {
  if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <n> <m>" << std::endl;
        return 1;  // Return an error code indicating incorrect usage
  }
  // Convert the command-line arguments to integers
  int n = std::atoi(argv[1]);
  int m = std::atoi(argv[2]);


  // double mat[n][m];
  // double vec[m];
  // double result[n];

  // randomization
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

  
  struct timeval start, end;
  gettimeofday(&start, nullptr);

  // actual vector multiplication
  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < m; j++) {
  //     result[i] += mat[i][m]*vec[m];
  //   }
  // }
  // return 0;
  gettimeofday(&end, nullptr);
  microseconds = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);




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





