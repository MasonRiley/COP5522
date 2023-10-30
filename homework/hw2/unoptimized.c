#include <microtime.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef float* Matrix;

Matrix createMatrix(int Rows, int Cols) {
  Matrix M;

  M = (Matrix)malloc(Rows * Cols * sizeof(M[0]));
  if (M == 0)
    fprintf(stderr, "Matrix allocation failed in file %s, line %d\n", __FILE__,
            __LINE__);

  return M;
}

void freeMatrix(Matrix M) {
  if (M) free(M);
}

void initMatrix(Matrix A, int Rows, int Cols) {
  int i, j;

  for (i = 0; i < Rows; i++)
    for (j = 0; j < Cols; j++) A[i * Cols + j] = 1.0 / (i + j + 2);
}

void matVecMult(Matrix A, Matrix B, Matrix C, int rows, int cols) {
  int i, k;

  memset(C, 0, rows * sizeof(C[0]));

  for (k = 0; k < cols; k++)
    for (i = 0; i < rows; i++) C[i] += A[i * cols + k] * B[k];
}

int main(int argc, char** argv) {
  int N, M, P = 1;
  Matrix A, B, C;
  double t, time1, time2;

  if (argc != 3) {
    fprintf(stderr, "USAGE: %s rows cols\n", argv[0]);
    exit(1);
  }

  N = atoi(argv[1]);
  M = atoi(argv[2]);

  A = createMatrix(N, M);
  B = createMatrix(M, P);
  C = createMatrix(N, P);

  initMatrix(A, N, M);
  initMatrix(B, M, P);
  memset(C, 0, N * P * sizeof(C[0]));

  time1 = microtime();
  matVecMult(A, B, C, N, M);
  time2 = microtime();

  t = time2 - time1;
  printf("\nTime = %g us\n", t);
  printf("Timer Resolution = %g us\n", getMicrotimeResolution());
  printf("Performance = %g Gflop/s\n", 2.0 * N * N * 1e-3 / t);
  printf("C[N/2] = %g\n\n", (double)C[N / 2]);

  freeMatrix(A);
  freeMatrix(B);
  freeMatrix(C);

  return 0;
}