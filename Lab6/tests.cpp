#include <assert.h>

#include "binary_search_tree.h"

int main() {
  binary_search_tree<int> bst1, bst2;
  bst1.insert(5);
  bst1.insert(13);
  bst1.insert(4);
  bst1.insert(25);
  bst1.insert(2);

  bst2.insert(5);
  bst2.insert(13);
  bst2.insert(4);
  bst2.insert(25);
  bst2.insert(2);

  assert(binary_search_tree<int>::compare_by_values(bst1, bst2) == 1);
  assert(binary_search_tree<int>::compare_by_structure(bst1, bst2) == 1);

  bst2.clear();
  bst2.insert(2);
  bst2.insert(4);
  bst2.insert(5);
  bst2.insert(13);
  bst2.insert(25);

  assert(binary_search_tree<int>::compare_by_values(bst1, bst2) == 1);
  assert(binary_search_tree<int>::compare_by_structure(bst1, bst2) == 0);

  bst1.insert(3);
  assert(binary_search_tree<int>::compare_by_values(bst1, bst2) == 0);
  assert(binary_search_tree<int>::compare_by_structure(bst1, bst2) == 0);

  bst2.insert(14);
  assert(binary_search_tree<int>::compare_by_values(bst1, bst2) == 0);
  assert(binary_search_tree<int>::compare_by_structure(bst1, bst2) == 0);
  return 0;
}