#pragma once

#include <cstddef>  // size_t
#include <utility>  // for pairs

template <typename key_type, typename value_type = char>
class binary_search_tree {
 private:
  struct node {
    std::pair<const key_type, value_type> data;
    node *left, *right;
    node(key_type key, value_type data)
        : data({key, data}), left(nullptr), right(nullptr){};
  };
  size_t _size;
  node *_root;

  void insert(key_type key, value_type value, node *current_node);
  void erase(key_type key, node *current_node, node *parent);
  void destroy_tree(node *current_node);
  void copy_node(node *this_node, node *other_node);
  static bool compare_by_structure(node *node1, node *node2);
  static void build_inorder(std::pair<key_type, value_type> *arr, int &index,
                            node *current_node);

 public:
  binary_search_tree();
  binary_search_tree(binary_search_tree &other);
  ~binary_search_tree();

  size_t size();

  void insert(key_type key, value_type value = value_type());
  void erase(key_type key);
  void clear();
  bool empty();
  static bool compare_by_values(binary_search_tree &t1, binary_search_tree &t2);
  static bool compare_by_structure(binary_search_tree &t1,
                                   binary_search_tree &t2);

  binary_search_tree &operator=(binary_search_tree const &other);
};

template <typename key_type, typename value_type>
binary_search_tree<key_type, value_type>::binary_search_tree()
    : _size(0), _root(nullptr) {}

template <typename key_type, typename value_type>
binary_search_tree<key_type, value_type>::~binary_search_tree() {
  destroy_tree(_root);
}

template <typename key_type, typename value_type>
size_t binary_search_tree<key_type, value_type>::size() {
  return _size;
}

template <typename key_type, typename value_type>
void binary_search_tree<key_type, value_type>::insert(
    const key_type key, value_type value,
    binary_search_tree::node *current_node) {
  if (key == current_node->data.first) {
    current_node->data.second = value;
    return;
  }
  if (key < current_node->data.first) {
    if (current_node->left) {
      insert(key, value, current_node->left);
    } else {
      current_node->left = new node(key, value);
      _size++;
    }
  }
  if (key > current_node->data.first) {
    if (current_node->right) {
      insert(key, value, current_node->right);
    } else {
      current_node->right = new node(key, value);
      _size++;
    }
  }
}

template <typename key_type, typename value_type>
void binary_search_tree<key_type, value_type>::erase(
    key_type key, binary_search_tree::node *current_node,
    binary_search_tree::node *parent) {
  if (current_node == nullptr) return;
  if (current_node->data.first > key) {
    erase(key, current_node->left, current_node);
  }
  if (current_node->data.first < key) {
    erase(key, current_node->right, current_node);
  }
  if (current_node->data.first == key) {
    if (!current_node->left && !current_node->right) {
      // no children
      if (current_node != _root) {
        parent->left == current_node ? parent->left = nullptr
                                     : parent->right = nullptr;
      } else {
        _root = nullptr;
      }
      delete current_node;
      _size--;
    } else if (current_node->left && current_node->right) {
      // 2 children
      node *mn = current_node->right;
      node *mn_parent = current_node;
      while (mn->left) {
        mn_parent = mn;
        mn = mn->left;
      }

      node *new_node = new node(mn->data.first, mn->data.second);
      new_node->left = current_node->left;
      new_node->right = current_node->right;
      if (current_node == _root) {
        _root = new_node;
      } else {
        if (parent->left == current_node) {
          parent->left = new_node;
        } else {
          parent->right = new_node;
        }
      }
      delete current_node;
      erase(mn->data.first, mn, mn_parent);
    } else {
      // 1 child
      node *child =
          current_node->left ? current_node->left : current_node->right;
      if (current_node == _root) {
        _root = child;
      } else {
        if (parent->left == current_node) {
          parent->left = child;
        } else {
          parent->right = child;
        }
      }
      delete current_node;
      _size--;
    }
  }
}

template <typename key_type, typename value_type>
void binary_search_tree<key_type, value_type>::insert(const key_type key,
                                                      value_type value) {
  if (!_root) {
    _root = new node(key, value);
    _size++;
    return;
  }
  insert(key, value, _root);
}

template <typename key_type, typename value_type>
void binary_search_tree<key_type, value_type>::erase(key_type key) {
  erase(key, _root, nullptr);
}

template <typename key_type, typename value_type>
void binary_search_tree<key_type, value_type>::clear() {
  destroy_tree(_root);
  _size = 0;
  _root = nullptr;
}

template <typename key_type, typename value_type>
void binary_search_tree<key_type, value_type>::destroy_tree(
    node *current_node) {
  if (current_node == nullptr) {
    return;
  }
  destroy_tree(current_node->left);
  destroy_tree(current_node->right);
  delete current_node;
}

template <typename key_type, typename value_type>
bool binary_search_tree<key_type, value_type>::empty() {
  return _size == 0;
}

template <typename key_type, typename value_type>
binary_search_tree<key_type, value_type>::binary_search_tree(
    binary_search_tree &other) {
  _size = other._size;
  if (other._root) {
    this->_root = new node(other._root->data.first, other._root->data.second);
    copy_node(this->_root, other._root);
  } else {
    _root = nullptr;
  }
}
template <typename key_type, typename value_type>
void binary_search_tree<key_type, value_type>::copy_node(
    binary_search_tree<key_type, value_type>::node *this_node,
    binary_search_tree<key_type, value_type>::node *other_node) {
  if (other_node->left) {
    this_node->left =
        new node(other_node->left->data.first, other_node->left->data.second);
    copy_node(this_node->left, other_node->left);
  }
  if (other_node->right) {
    this_node->right =
        new node(other_node->right->data.first, other_node->right->data.second);
    copy_node(this_node->right, other_node->right);
  }
}

template <typename key_type, typename value_type>
binary_search_tree<key_type, value_type>
    &binary_search_tree<key_type, value_type>::operator=(
        binary_search_tree const &other) {
  clear();
  if (other._root) {
    this->_root = new node(other._root->data.first, other._root->data.second);
    copy_node(this->_root, other._root);
  }
  return *this;
}
template <typename key_type, typename value_type>
bool binary_search_tree<key_type, value_type>::compare_by_values(
    binary_search_tree<key_type, value_type> &t1,
    binary_search_tree<key_type, value_type> &t2) {
  if (t1.size() != t2.size()) {
    return false;
  }
  auto *inorder1 = new std::pair<key_type, value_type>[t1._size];
  auto *inorder2 = new std::pair<key_type, value_type>[t2._size];
  int i = 0;
  build_inorder(inorder1, i, t1._root);
  i = 0;
  build_inorder(inorder2, i, t2._root);
  for (int i = 0; i < t1.size(); i++) {
    if (inorder1[i] != inorder2[i]) {
      delete[] inorder1;
      delete[] inorder2;
      return false;
    }
  }
  delete[] inorder1;
  delete[] inorder2;
  return true;
}
template <typename key_type, typename value_type>
bool binary_search_tree<key_type, value_type>::compare_by_structure(
    binary_search_tree<key_type, value_type> &t1,
    binary_search_tree<key_type, value_type> &t2) {
  if (t1.size() != t2.size()) {
    return false;
  }
  return compare_by_structure(t1._root, t2._root);
}
template <typename key_type, typename value_type>
bool binary_search_tree<key_type, value_type>::compare_by_structure(
    binary_search_tree<key_type, value_type>::node *node1,
    binary_search_tree<key_type, value_type>::node *node2) {
  if (node1 && !node2 || !node1 && node2) {
    return false;
  }
  if (!node1 && !node2) {
    return true;
  }
  return node1->data == node2->data &&
         compare_by_structure(node1->left, node2->left) &&
         compare_by_structure(node1->right, node2->right);
}
template <typename key_type, typename value_type>
void binary_search_tree<key_type, value_type>::build_inorder(
    std::pair<key_type, value_type> *arr, int &index,
    binary_search_tree<key_type, value_type>::node *current_node) {
  if (!current_node) return;
  build_inorder(arr, index, current_node->left);
  arr[index] = current_node->data;
  index++;
  build_inorder(arr, index, current_node->right);
}
