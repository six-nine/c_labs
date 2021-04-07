#include <limits.h>
#include <stdio.h>

#include "src/string/str.h"
#include "src/text/text.h"

int main() {
  const unsigned int MAX_STR_LENGTH = 128;
  char in_str[MAX_STR_LENGTH], text_mask[MAX_STR_LENGTH];
  int mask_length = 0;
  char min_word[MAX_STR_LENGTH], max_word[MAX_STR_LENGTH];
  int min_word_size = INT_MAX, max_word_size = 0;
  text txt;
  txt.first_word = NULL;
  txt.last_word = NULL;

  while (gets(in_str) != NULL && str_len(in_str) > 0) {
    int i = 0, n = str_len(in_str);
    in_str[n] = '\n';
    n++;
    in_str[n] = '\0';
    char current_word[MAX_STR_LENGTH];
    int word_size = 0;
    for (i = 0; i < n; i++) {
      if (in_str[i] == '\n' || in_str[i] == ' ' || in_str[i] == '\t' ||
          in_str[i] == '.' || in_str[i] == '?' || in_str[i] == '!') {
        current_word[word_size] = '\0';
        if (word_size == 0) {
          text_mask[mask_length++] = in_str[i];
          continue;
        }
        if (word_size < min_word_size) {
          min_word_size = word_size;
          str_cpy(min_word, current_word);
        }
        if (word_size > max_word_size) {
          max_word_size = word_size;
          str_cpy(max_word, current_word);
        }
        push_word(&txt, current_word);
        text_mask[mask_length++] = '@';
        text_mask[mask_length++] = in_str[i];
        /* clear word */
        current_word[0] = '\0';
        word_size = 0;
      } else {
        current_word[word_size++] = in_str[i];
      }
      if (in_str[i] == '.' || in_str[i] == '?' || in_str[i] == '!') {
        /* end of sentence */
        int i = 0;
        word *w = txt.first_word;
        for (i = 0; i < mask_length; i++) {
          if (text_mask[i] == '@') {
            if (str_cmp(w->str, min_word) == 0) {
              printf("%s", max_word);
            } else if (str_cmp(w->str, max_word) == 0) {
              printf("%s", min_word);
            } else {
              printf("%s", w->str);
            }
            w = w->next;
          } else {
            printf("%c", text_mask[i]);
          }
        }
        destruct_text(&txt);
        min_word[0] = '\0';
        max_word[0] = '\0';
        min_word_size = INT_MAX;
        max_word_size = 0;
        mask_length = 0;
      }
    }
  }

  destruct_text(&txt);

  return 0;
}
