#pragma once
#include <vector>
#include "stack.h"
#include "queue.h"

struct query{
  size_t stack_number;
  char type;
  int data;
  query(int stack_number, char type, int data){
    this->stack_number = stack_number;
    this->type = type;
    this->data = data;
  }
};
std::vector<stack<int>> process_stacks(int n, queue<query> que);
