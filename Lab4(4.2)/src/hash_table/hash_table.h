#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdlib.h>
#include <string.h>

#include "../string/str.h"
#include "list.h"

typedef struct hash_table {
  unsigned long long MOD;
  unsigned long long capacity;
  list* table;
} hash_table;

unsigned long long hash(char* str, unsigned long long MOD);
int init_table(struct hash_table* hash_t);
int insert_to_hash_table(struct hash_table* hash_t, char* key, char* value);
void destruct_hash_table(struct hash_table* hash_t);
list_item* find(struct hash_table* hash_t, char* key);

#endif