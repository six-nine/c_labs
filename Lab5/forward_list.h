#pragma once

#include <cstddef>
template<typename T>
class forward_list{
 private:
  struct node{
    T data;
    node *next;
    item(T data){
      this->data = data;
      next = nullptr;
    }
  };
  node *_head, *_tail, *_tail_prev;
  size_t _size;

 public:
  forward_list();
  forward_list(forward_list &other);
  ~forward_list();

  void push_front(T data);
  void push_back(T data);
  void pop_front();
  void pop_back();
  void clear();

  forward_list &operator=(forward_list &other);
  const forward_list &operator=(forward_list &other) const;

};

template<typename T>
forward_list<T>::forward_list() : _size(0), _head(nullptr), _tail(nullptr), _tail_prev(nullptr) { }

template<typename T>
forward_list<T>::forward_list(forward_list &other) {
  node *current = other._head;
  while (current){
    push_back(current->data);
    current = current->next;
  }
}

template<typename T>
forward_list<T>::~forward_list() {
  clear();
}

template<typename T>
void forward_list<T>::push_front(T data) {
  if (_head){
    node* old_head = _head;
    _head = new node(data);
    _head->next = old_head;
  } else {
    _head = new node(data);
    _tail = _head;
  }
  _size++;
}

template<typename T>
void forward_list<T>::push_back(T data) {
  if (_tail){
    _tail->next = new node(data);
    _tail = _tail->next;
  } else {
    _head = new node(data);
    _tail = _head;
  }
  _size++;
}

template<typename T>
void forward_list<T>::pop_front() {
  if (!_head){
    // list is empty
    return;
  }
  node *new_head = _head->next;
  delete _head;
  _head = new_head;
  if (!_head){
    // last item was deleted
    _tail = nullptr;
  }
  _size--;
}

template<typename T>
void forward_list<T>::pop_back() {
  if ()
}
template<typename T>
void forward_list<T>::clear() {

}
template<typename T>
forward_list &forward_list<T>::operator=(forward_list &other) {

}
template<typename T>
const forward_list &forward_list<T>::operator=(forward_list &other) const {

}










