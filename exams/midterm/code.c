#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
  int i, size = 100000000;
  float *A, *B, *C;
  double sum = 0.0;

  // TODO Allocated aligned memory for A, B, and C

  if ((A == 0) || (B == 0) || (C == 0)) {
    fprintf(stderr, "Memory allocation failed in file %s, line %d\n", __FILE__,
            __LINE__);
    exit(1);
  }
  for (i = 0; i < size; i++) {
    B[i] = i * 0.00002;
    C[i] = -i * 0.00003;
  }
  for (i = 0; i < size; i++) {
    A[i] += C[i] * B[i] * B[i] * 1000.0;
    sum += A[i];
  }
  printf("Sum: %f\n", sum);
  return 0;
}