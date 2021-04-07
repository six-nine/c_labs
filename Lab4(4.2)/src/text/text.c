#include "text.h"

int push_word(text *txt, char *word) {
  if (txt->first_word == NULL) {
    txt->first_word = malloc(sizeof(word));
    txt->last_word = txt->first_word;
    if (txt->first_word == NULL) {
      /* memory error */
      return 1;
    }
  } else {
    txt->last_word->next = malloc(sizeof(word));
    if (txt->last_word->next == NULL) {
      /* memory error */
      return 1;
    }
    txt->last_word = txt->last_word->next;
  }
  txt->last_word->str = (char *)malloc(sizeof(char) * (str_len(word) + 1));
  if (txt->last_word->str == NULL) {
    return 1;
  }
  str_cpy(txt->last_word->str, word);
  return 0;
}

void destruct_text(text *txt) {
  word *curr_word = txt->first_word;
  while (curr_word != NULL) {
    word *nxt = curr_word->next;
    free(curr_word->str);
    free(curr_word);
    curr_word = nxt;
  }
}
