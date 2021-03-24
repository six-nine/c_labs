#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "main.h"
#include "matrix_memory.h"

int **generate_matrix(n, m) {
  int **matrix = allocate_matrix(n, m);
  if (matrix == NULL) {
    return NULL;
  }
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < i; j++) {
      matrix[i][j] = 0;
    }
    for (j = i; j < m; j++) {
      matrix[i][j] = rand() % 9 + 1;
    }
  }
  return matrix;
}

int **shuffle_matrix(int **arr, int n, int m) {
  int **matrix = allocate_matrix(n, m);
  int i, j;
  if (matrix == NULL) {
    return NULL;
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      matrix[i][j] = arr[i][j];
    }
  }
  for (i = 0; i < n; i++) {
    int k = rand() % (n - i) + i;
    for (j = 0; j < m; j++) {
      int temp = matrix[i][j];
      matrix[i][j] = matrix[k][j];
      matrix[k][j] = temp;
    }
  }
  for (j = 0; j < m; j++) {
    int k = rand() % (m - j) + j;
    for (i = 0; i < n; i++) {
      int temp = matrix[i][j];
      matrix[i][j] = matrix[i][k];
      matrix[i][k] = temp;
    }
  }
  return matrix;
}

void test() {
  int t;
  for (t = 1; t <= 5; t++) {
    int i, j;
    int n = rand() % 100 + 1, m = n;
    printf("TEST %d: n = %d\n", t, n);
    int **matrix = generate_matrix(n, m);
    if (matrix == NULL) {
      return;
    }
    int **shuffled_matrix = shuffle_matrix(matrix, n, m);
    if (shuffled_matrix == NULL) {
      return;
    }
    restore_matrix(shuffled_matrix, n);
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        assert(matrix[i][j] == shuffled_matrix[i][j]);
      }
    }
    printf("TEST %d PASSED\n", t);
    clear_matrix(matrix, n);
    clear_matrix(shuffled_matrix, n);
  }
}
#undef main

int main() {
  test();
  return 0;
}