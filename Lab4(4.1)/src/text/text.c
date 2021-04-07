#include "text.h"

int push_word(text *txt, char *word) {
  if (txt->first_word == NULL) {
    txt->first_word = (struct word *)malloc(sizeof(word));
    txt->last_word = txt->first_word;
    if (txt->first_word == NULL) {
      return 0;
    }
    txt->first_word->next = NULL;
  } else {
    txt->last_word->next = (struct word *)malloc(sizeof(word));
    if (txt->last_word->next == NULL) {
      return 0;
    }
    txt->last_word = txt->last_word->next;
    txt->last_word->next = NULL;
  }
  txt->last_word->str = (char *)malloc(sizeof(char) * (str_len(word) + 1));
  if (txt->last_word->str == NULL) {
    return 0;
  }
  str_cpy(txt->last_word->str, word);
  return 1;
}

void destruct_text(text *txt) {
  word *curr_word = txt->first_word;
  while (curr_word != NULL) {
    word *nxt = curr_word->next;
    free(curr_word->str);
    free(curr_word);
    curr_word = nxt;
  }
  txt->first_word = NULL;
  txt->last_word = NULL;
}
