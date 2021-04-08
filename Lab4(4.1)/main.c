#include <limits.h>
#include <stdio.h>

#include "src/string/str.h"
#include "src/text/text.h"

int main() {
  const unsigned int MAX_STR_LENGTH = 128;
  char *in_str, *text_mask;
  int mask_length = 0;
  char *min_word, *max_word;
  int min_word_size = INT_MAX, max_word_size = 0;
  int shortest_word_size = INT_MAX;
  int longest_word_size = 0;
  in_str = malloc(MAX_STR_LENGTH * sizeof(char));
  text_mask = malloc(MAX_STR_LENGTH * sizeof(char));
  min_word = malloc(MAX_STR_LENGTH * sizeof(char));
  max_word = malloc(MAX_STR_LENGTH * sizeof(char));

  if (!in_str || !text_mask || !min_word || !max_word) {
    if (in_str) free(in_str);
    if (text_mask) free(text_mask);
    if (min_word) free(min_word);
    if (max_word) free(max_word);
    printf("Error");
    return 1;
  }

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
        if (!push_word(&txt, current_word)) {
          printf("Memory error.");
          destruct_text(&txt);
          return 1;
        }
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
        if (max_word_size > longest_word_size) {
          longest_word_size = max_word_size;
        }
        if (min_word_size < shortest_word_size) {
          shortest_word_size = min_word_size;
        }
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
  printf("\nLongest word contains %d letters\n", longest_word_size);
  printf("Shortest word contains %d letters\n", shortest_word_size);
  free(in_str);
  free(text_mask);
  free(min_word);
  free(max_word);
  destruct_text(&txt);

  return 0;
}
