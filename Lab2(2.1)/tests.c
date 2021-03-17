#include <assert.h>
#include <math.h>

#include "main.h"

#undef main
int main() {
  double eps = 1e-2;
  printf("%f\n", get_surface_area(5) - 314.15);
  assert(fabs(get_surface_area(5) - 314.15) < eps);
  assert(get_volume(5) - 523.59 < eps);
  assert(get_tetradeon(5) - 8.16 < eps);
  assert(get_cross_sectional_area(5, 4) - 28.27 < eps);

  return 0;
}