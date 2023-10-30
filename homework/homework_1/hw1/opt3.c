// This code implements Intel SIMD Intrinsics

#include <microtime.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <xmmintrin.h>

typedef float* Matrix;

Matrix createMatrix(int rows, int cols) {
  Matrix M;

  M = (Matrix)malloc(rows * cols * sizeof(M[0]));
  if (M == 0)
    fprintf(stderr, "Matrix allocation failed in file %s, line %d\n", __FILE__,
            __LINE__);

  return M;
}

void freeMatrix(Matrix M) {
  if (M) free(M);
}


void initMatrix(Matrix A, int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            A[i * cols + j] = 1.0 / (i + j + 2);
}

// Implements Intel SIMD Intrinsics
void matVecMult(Matrix A, Matrix B, Matrix C, int rows, int cols) {
    int i, k;
    __m128 a, b, sum; // Declare SIMD registers for holding values from a and b and summing them up
    
    // Calculate how many elements can be processed using SIMD 
    int simd_end = cols - (cols % 4); 
    
    for (i = 0; i < rows; i++) {
        sum = _mm_setzero_ps();  // Initialize sum to zero using SIMD instructions
        
        // Begin SIMD sum loop
        for (k = 0; k < simd_end; k += 4) {  // Loop over the elements of matrix A and B in chunks of 4 since SIMD can process 4 floats in parallel
            // Load 4 elements from matrix A into an SIMD register. 
            // I had trouble implementing 16-byte aligned memory so I use
            // unaligned load because memory might not be 16-byte aligned
            a = _mm_loadu_ps(&A[i * cols + k]); 
            
            // Load 4 elements from matrix B into another SIMD register
            b = _mm_loadu_ps(&B[k]);
            
            // Multiply the elements from A and B and add to the sum
            sum = _mm_add_ps(sum, _mm_mul_ps(a, b));
        }
        
        // Store the 4 SIMD elements in an array so we can sum them up
        float temp[4];
        _mm_store_ps(temp, sum);
        for (k = 0; k < 4; k++)
            C[i] += temp[k];
        
        // This loop handles the tail elements that are left after processing with SIMD
        for (k = simd_end; k < cols; k++) 
            C[i] += A[i * cols + k] * B[k];
    }
}

int main(int argc, char** argv) {
  int n, m, p = 1;
  Matrix A, B, C;
  double t, time1, time2;

  if (argc != 3) {
    fprintf(stderr, "USAGE: %s rows cols\n", argv[0]);
    exit(1);
  }

  n = atoi(argv[1]);
  m = atoi(argv[2]);

  A = createMatrix(n, m);
  B = createMatrix(m, p);
  C = createMatrix(n, p);

  initMatrix(A, n, m);
  initMatrix(B, m, p);
  memset(C, 0, n * p * sizeof(C[0]));

  // measure time
  time1 = microtime();
  matVecMult(A, B, C, n, m);
  time2 = microtime();

  t = time2 - time1;

  // Print results
  printf("\nTime = %g us\n", t);
  printf("Timer Resolution = %g us\n", getMicrotimeResolution());
  printf("Performance = %g Gflop/s\n", 2.0 * n * n * 1e-3 / t);
  printf("C[N/2] = %g\n\n", (double)C[n / 2]);

  freeMatrix(A);
  freeMatrix(B);
  freeMatrix(C);

  return 0;
}