#include "process_stacks.h"

std::vector<stack<int>> process_stacks(int n, queue<query> que){
  std::vector<stack<int>> ret(n);
  while (!que.empty()){
    query current_query = que.front();
    que.pop();
    if (current_query.type == 'A'){
      // add
      ret[current_query.stack_number - 1].push(current_query.data);
    } else {
      // delete
      ret[current_query.stack_number - 1].erase(current_query.data);
    }
  }
  return ret;
}
