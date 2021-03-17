#include <assert.h>

#include "main.h"

#undef main
int main() {
  assert(get_n(1, 0.001) == 3);
  assert(get_n(0.1, 0.1) == 0);
  assert(get_n(1.5, 0.0001) == 5);
  assert(get_n(0.5, 0.00001) == 3);
  return 0;
}