#include "main.h"

#include <stdio.h>

int is_perfect(int number) {
  if (number < 2 || number > 200000) {
    return 0;
  }
  unsigned long long sum = 1;
  int i;
  for (i = 2; i * i <= number; i++) {
    if (number % i == 0) {
      sum += i;
      sum += number / i;
    }
  }
  return (sum == number) ? 1 : 0;
}

int main() {
  int n;
  printf("Enter n:\n");
  int correct_input = 0;
  while (!correct_input) {
    int result = scanf("%d", &n);
    if (result == 1 && n >= 1 && n <= 200000) {
      correct_input = 1;
    } else {
      while (getchar() != '\n') {
      }
      printf("Incorrect input. Try again.\n");
    }
  }
  int i;
  for (i = 2; i <= n; i++) {
    if (is_perfect(i)) {
      printf("%d ", i);
    }
  }
  printf("\n");

  return 0;
}
