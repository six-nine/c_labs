#include "process_stacks.h"
#include <cassert>

int main() {
  queue<query> test_q;
  test_q.push(query(5, 'A', 13));
  test_q.push(query(1, 'A', 45));
  test_q.push(query(2, 'A', 11));
  test_q.push(query(4, 'A', 16));
  test_q.push(query(4, 'A', 98));
  test_q.push(query(1, 'A', 35));
  test_q.push(query(4, 'D', 16));
  test_q.push(query(3, 'A', 2));
  test_q.push(query(3, 'A', 2));
  test_q.push(query(3, 'A', 15));
  test_q.push(query(3, 'D', 2));
  test_q.push(query(2, 'A', 105));
  test_q.push(query(2, 'A', 100));
  std::vector<stack<int>> result = process_stacks(5, test_q);
  assert(result[0].size() == 2);
  assert(result[1].size() == 3);
  assert(result[2].size() == 1);
  assert(result[3].size() == 1);
  assert(result[4].size() == 1);
  assert(result[0].top() == 35);
  assert(result[3].top() == 98);
  return 0;
}