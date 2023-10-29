#include <microtime.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <xmmintrin.h> // Include header for SSE intrinsics

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

void matVecMult(Matrix A, Matrix B, Matrix C, int rows, int cols) {
    int i, k;
    __m128i a, b, sum // Declare SIMD registers for holding values from A and B and summing them up.
    
    // Calculate how many elements can be processed using SIMD. 
    // Example: If cols = 10 then simd_end = 8, because 8 is the largest multiple of 4 less than 10.
    int simd_end = 
    
    for (i = 0; i < rows; i++) {
        sum =  // Initialize the sum to zero using SIMD instructions.
        
        // SIMD part starts
        for (k = 0; k < ; k += ) {  // Loop over the elements of matrix A and B in chunks of 4 since SIMD can process 4 ints in parallel.
            // Load 4 elements from matrix A into a SIMD register. Use unaligned load because memory might not be 16-byte aligned.
            a =  
            
            // Load 4 corresponding elements from matrix B into another SIMD register.
            b = 
            
            // Multiply the elements from A and B and add to the sum.
            // This adds a[0]*b[0], a[1]*b[1], ... to corresponding elements in sum.
            sum = 
        }
        
        // Sum up the elements stored in the sum SIMD register.
        // Store the 4 SIMD elements in an array so we can access them.
        float temp[4];
        (temp, sum);
        for (k = 0; k < 4; k++)  // Sum these 4 values to C[i]. 
            C[i] += temp[k];
        
        // Handle any remaining elements in A and B matrices after SIMD operations.
        // This loop deals with the tail elements that are left after processing with SIMD.
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