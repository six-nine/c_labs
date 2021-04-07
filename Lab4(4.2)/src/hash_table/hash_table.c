#include "hash_table.h"

unsigned long long hash(char* str, unsigned long long MOD) {
  unsigned int n = str_len(str);
  int i = 0;
  unsigned long long result = 0;
  unsigned long long p = 1;
  for (i = 0; i < n; i++) {
    result += str[i] * p;
    p *= MOD;
  }
  return result;
}

int init_table(struct hash_table* hash_t) {
  hash_t->MOD = 257;
  hash_t->capacity = 177013;
  hash_t->table = (list*)malloc(hash_t->capacity * sizeof(list));
  if (hash_t->table != NULL) {
    int i;
    for (i = 0; i < hash_t->capacity; i++) {
      hash_t->table[i].first_item = NULL;
      hash_t->table[i].last_item = NULL;
    }
  }
  return hash_t->table != NULL;
}

int insert_to_hash_table(struct hash_table* hash_t, char* key, char* value) {
  unsigned long long index = hash(key, hash_t->MOD) % hash_t->capacity;
  if (hash_t->table[index].first_item == NULL) {
    // first item with this hash
    hash_t->table[index].first_item = (list_item*)malloc(sizeof(list_item));
    hash_t->table[index].last_item = hash_t->table[index].first_item;
    if (hash_t->table[index].first_item == NULL) {
      return 0;
    }
  } else {
    hash_t->table[index].last_item->next =
        (list_item*)malloc(sizeof(list_item));
    if (hash_t->table[index].last_item->next == NULL) {
      return 0;
    }
    hash_t->table[index].last_item = hash_t->table[index].last_item->next;
  }
  hash_t->table[index].last_item->next = NULL;

  hash_t->table[index].last_item->key =
      malloc(sizeof(char) * (str_len(key) + 1));
  if (hash_t->table[index].last_item->key == NULL) {
    return 0;
  }
  str_cpy(hash_t->table[index].last_item->key, key);

  hash_t->table[index].last_item->value =
      malloc(sizeof(char) * (str_len(value) + 1));
  if (hash_t->table[index].last_item->value == NULL) {
    return 0;
  }
  str_cpy(hash_t->table[index].last_item->value, value);
  return 1;
}

void destruct_hash_table(struct hash_table* hash_t) {
  int i;
  for (i = 0; i < hash_t->capacity; i++) {
    list_item* curr_node = hash_t->table[i].first_item;
    while (curr_node != NULL) {
      list_item* nxt = curr_node->next;
      if (curr_node->key != NULL) free(curr_node->key);
      if (curr_node->value != NULL) free(curr_node->value);
      free(curr_node);
      curr_node = nxt;
    }
  }
  free(hash_t->table);
}

list_item* find(struct hash_table* hash_t, char* key) {
  unsigned long long index = hash(key, hash_t->MOD) % hash_t->capacity;
  list_item* current = hash_t->table[index].first_item;
  while (current != NULL) {
    if (str_cmp(current->key, key) == 0) {
      return current;
    }
    current = current->next;
  }
  return NULL;
}
