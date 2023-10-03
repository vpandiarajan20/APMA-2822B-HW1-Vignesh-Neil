#include <stdio.h>
#include <iostream>
#include <vector>
#include <random>
#include <sys/time.h>

// randomization
std::random_device rd;
std::mt19937 gen(rd());  // Mersenne Twister 19937 generator
std::uniform_real_distribution<double> distribution(1.0, 100.0);

double getFlopRate(int flops, long ms) {
  double flopsms = ((double) flops)/ ((double) ms);
  // return flopsms;
  return flopsms / 1000.0;
}

void instantiateMatVec(int n, int m, double **mat, double *vec) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        mat[i][j] = distribution(gen);  // Generate a random double value and store it in the matrix
    }
  }
  for (int i = 0; i < m; i++) {
    vec[i] = distribution(gen);
  }
}

void multiplyVec(int n, int m, double **mat, double *vec, double *result) {
  // actual vector multiplication
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      result[i] += mat[i][j]*vec[j];
    }
  }
}

void multiplyVec4(int n, int m, double **mat, double *vec, double *result) {
  // unroll 4
  for (int i = 0; i < n; i++) {
    int unrolled_iters = m / 4;
    for (int j = 0; j < unrolled_iters * 4; j = j + 4) {
      result[i] += mat[i][j]*vec[j];
      result[i] += mat[i][j+1]*vec[j+1];
      result[i] += mat[i][j+2]*vec[j+2];
      result[i] += mat[i][j+3]*vec[j+3];
    }
    for (int j = unrolled_iters * 4; j < m; j++) {
      result[i] += mat[i][j]*vec[j];
    }
  }
}

void multiplyVec8(int n, int m, double **mat, double *vec, double *result) {
  // unroll 8
  for (int i = 0; i < n; i++) {
    int unrolled_iters = m / 8;
    for (int j = 0; j < unrolled_iters * 8; j = j + 8) {
      result[i] += mat[i][j]*vec[j];
      result[i] += mat[i][j+1]*vec[j+1];
      result[i] += mat[i][j+2]*vec[j+2];
      result[i] += mat[i][j+3]*vec[j+3];
      result[i] += mat[i][j+4]*vec[j+4];
      result[i] += mat[i][j+5]*vec[j+5];
      result[i] += mat[i][j+6]*vec[j+6];
      result[i] += mat[i][j+7]*vec[j+7];
    }
    for (int j = unrolled_iters * 8; j < m; j++) {
      result[i] += mat[i][j]*vec[j];
    }
  }
}

void basicMatVecMul(int n, int m, int unroll) {
  // std::cout << "initializing" << std::endl;

  // non-contiguous memory alloc
  double **mat;
  mat = new double*[n];
  for (int i = 0; i < n; i++) {
    mat[i] = new double[m];
  }

  double *vec;
  vec = new double[m];
  double *result = new double[n];

  instantiateMatVec(n, m, mat, vec);

  // std::cout << "multiplying" << std::endl;

  struct timeval start, end;
  gettimeofday(&start, nullptr);

  if (unroll == 1) {
    multiplyVec(n, m, mat, vec, result);
  } else if (unroll == 4) {
    multiplyVec4(n, m, mat, vec, result);
  } else if (unroll == 8){
    multiplyVec8(n, m, mat, vec, result);
  } else {
    std::cout << "error" << std::endl;
  }

  gettimeofday(&end, nullptr);
  long microseconds = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);

  // int milliseconds = microseconds / 1000;

  double floprate = getFlopRate(2*m*n, microseconds);

  std::cout << "Rows: " << n << ", Cols: " << m << ", Time:" << microseconds << ", Floprate: " << floprate << ", unroll:" << unroll << std::endl;
  
  for (int i = 0; i < n; i++) {
    delete(mat[i]);
  }
  delete[] mat;
  return;
}

void contiguousMatVecMul(int n, int m, int unroll) {
  // contiguous mem
  double **mat;
  mat = new double*[n];
  mat[0] = new double[n*m];

  double *vec;
  vec = new double[m];

  for (int i = 1; i < n; i++) {
    mat[i] = mat[0] + i * m;
  }

  double *result = new double[n];
  
  instantiateMatVec(n, m, mat, vec);

  // std::cout << "multiplying" << std::endl;

  struct timeval start, end;
  gettimeofday(&start, nullptr);

  if (unroll == 1) {
    multiplyVec(n, m, mat, vec, result);
  } else if (unroll == 4) {
    multiplyVec4(n, m, mat, vec, result);
  } else if (unroll == 8){
    multiplyVec8(n, m, mat, vec, result);
  } else {
    std::cout << "error" << std::endl;
  }

  gettimeofday(&end, nullptr);
  int microseconds = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);

  double floprate = getFlopRate(2*m*n, microseconds);

  std::cout << "Rows: " << n << ", Cols: " << m << ", Time:" << microseconds << ", Floprate: " << floprate << ", unroll:" << unroll << std::endl;

  delete[] mat[0];
  return;
}

int main(int argc, char* argv[]) {
  if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <algorithm>" << argv[1] << "<unroll>" << std::endl;
        return 1;  // Return an error code indicating incorrect usage
  }

  std::string algorithm = std::string(argv[1]);
  int unroll = atoi(argv[2]);

  void (*multFunc)(int, int, int);
  if (algorithm == "basic") {
    multFunc = basicMatVecMul;
  } else if (algorithm == "contiguous") {
    multFunc = contiguousMatVecMul;
  } else {
    std::cerr << "Invalid algorithm" << std::endl;
    return 1;
  }

  int rowSizes[3] = {10, 1000, 10000};
  int colSizes[3] = {10, 1000, 10000};

  for (int r : rowSizes) {
    for (int c : colSizes){
      multFunc(r, c, unroll);
    }
  }
  return 0;
}
