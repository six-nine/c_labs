#ifndef TEXT_H
#define TEXT_H

#include <stdlib.h>

#include "../string/str.h"

typedef struct word {
  struct word *next;
  char *str;
} word;

typedef struct text {
  struct word *first_word, *last_word;
} text;

int push_word(text *txt, char *word);
void destruct_text(text *txt);

#endif
