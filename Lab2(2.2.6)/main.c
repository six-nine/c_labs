#include "main.h"

#include <math.h>
#include <stdio.h>
#include <string.h>

#ifndef M_PI
#define M_PI 3.141592
#endif

void get_validated_double(double *variable, double min_value, double max_value,
                          char *message) {
  double good_input = 0;
  while (!good_input) {
    if (strlen(message) != 0) {
      printf("%s", message);
    }
    int result = scanf("%lf", &*variable);
    good_input =
        (result == 1 && *variable >= min_value && *variable <= max_value);
    while (getchar() != '\n') {
    }
    if (!good_input) {
      printf("Incorrect input. Try again\n");
    }
  }
}

int get_n(double x, double eps) {
  double sinx = sin(x);
  int n = 0;
  double result = 0;
  int fact = 1;
  while (fabs(sinx - result) > eps) {
    n++;
    if (n != 1) {
      fact *= (2 * n - 1) * (2 * n - 2);
    }
    result += pow(-1, n - 1) * pow(x, 2 * n - 1) / fact;
  }
  return n;
}

int main() {
  double x, eps;
  get_validated_double(&x, 0, M_PI / 2, "Enter x between 0 and П/2: ");
  get_validated_double(&eps, 0, 1000, "Enter eps between 0 and 1000: ");
  int n = get_n(x, eps);
  printf("N = %d\n", n);

  return 0;
}