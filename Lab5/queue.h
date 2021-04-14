#pragma once
#include <list>

template<typename T>
class queue {
 private:
  std::list<T> _list;
 public:
  queue();
  queue(queue &other);
  ~queue();

  size_t size();
  bool empty();
  void push(T data);
  void pop();
  T &front();
};

template<typename T>
queue<T>::queue() {}
template<typename T>
queue<T>::queue(queue &other) {
  _list = other._list;
}
template<typename T>
queue<T>::~queue() {}
template<typename T>
void queue<T>::push(T data) {
  _list.push_back(data);
}
template<typename T>
void queue<T>::pop() {
  _list.pop_front();
}
template<typename T>
T &queue<T>::front() {
  return _list.front();
}
template<typename T>
size_t queue<T>::size() {
  return _list.size();
}
template<typename T>
bool queue<T>::empty() {
  return _list.size() == 0;
}
