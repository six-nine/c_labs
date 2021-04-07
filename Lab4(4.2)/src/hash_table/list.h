#ifndef LIST_H
#define LIST_H

typedef struct list_item {
  struct list_item *next;
  char *key;
  char *value;
} list_item;

typedef struct list {
  list_item *first_item, *last_item;
} list;

#endif