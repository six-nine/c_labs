#include <iostream>

#include "binary_search_tree.h"

using namespace std;

int main() {
  int n, m;
  binary_search_tree<int> bst1, bst2;
  cout << "Enter first tree size: " << endl;
  cin >> n;
  cout << "Enter second tree size: " << endl;
  cin >> m;
  cout << "Enter first BST items: " << endl;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    bst1.insert(x);
  }
  cout << "Enter second BST items: " << endl;
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    bst2.insert(x);
  }
  cout << "Comparation by structure returnded "
       << binary_search_tree<int>::compare_by_structure(bst1, bst2) << endl;
  cout << "Comparation by values returnded "
       << binary_search_tree<int>::compare_by_values(bst1, bst2) << endl;
  return 0;
}
