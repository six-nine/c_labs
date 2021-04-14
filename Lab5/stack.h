#pragma once

#include <forward_list>

template<typename T>
class stack{
 private:
  std::forward_list<T> _list;
  size_t _size;
 public:
  size_t size();
  stack();
  ~stack();
  stack(stack &other);

  void push(T data);
  void pop(T data);
  void erase(T value);
  T &top();
};

template<typename T>
stack<T>::stack() : _size(0){ }

template<typename T>
stack<T>::stack(stack &other) {
  _list = other._list;
  _size = other._size;
}

template<typename T>
stack<T>::~stack() {

}

template<typename T>
void stack<T>::push(T data) {
  _list.push_front(data);
  _size++;
}

template<typename T>
void stack<T>::pop(T data) {
  _list.pop_front();
}
template<typename T>
void stack<T>::erase(T value) {
  _list.remove(value);
  _size = 0;
  for (auto i: _list){
    _size++;
  }
}
template<typename T>
T &stack<T>::top() {
  return _list.front();
}
template<typename T>
size_t stack<T>::size(){
  return _size;
}
