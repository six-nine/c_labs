#include "matrix_memory.h"

#include <stdlib.h>
void clear_matrix(int **matrix, int n) {
  int i;
  for (i = 0; i < n; i++) {
    free((matrix[i]));
  }
  free(matrix);
}

int **allocate_matrix(int n, int m) {
  int **matrix = (int **)malloc(n * sizeof(int *));
  if (matrix == NULL) {
    return NULL;
  }
  int i, j;
  for (i = 0; i < n; i++) {
    matrix[i] = (int *)malloc(m * sizeof(int));
    if (matrix[i] == NULL) {
      clear_matrix(matrix, i);
      return NULL;
    }
  }
  return matrix;
}