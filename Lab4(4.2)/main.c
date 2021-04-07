#include <stdio.h>

#include "src/hash_table/hash_table.h"
#include "src/string/str.h"
#include "src/text/text.h"

int main() {
  const unsigned int MAX_WORD_LENGTH = 128;

  // ------- get dictionary ------ //
  hash_table hash_t;
  if (!init_table(&hash_t)) {
    printf("Error while initialising hash table");
    return 1;
  }
  FILE *input;
  input = fopen("tests/dict.txt", "r");
  if (input == NULL) {
    destruct_hash_table(&hash_t);
    printf("Unable to open file");
    return 1;
  }
  char key[MAX_WORD_LENGTH];
  char value[MAX_WORD_LENGTH];
  while (fscanf(input, "%128s %128s", key, value) != EOF) {
    if (!insert_to_hash_table(&hash_t, key, value)) {
      destruct_hash_table(&hash_t);
      fclose(input);
      printf("Error while adding element to hash table.");
      return 1;
    }
  }
  fclose(input);

  input = fopen("tests/text.txt", "r");
  if (input == NULL) {
    printf("ERROR!!! Unable to open file");
    destruct_hash_table(&hash_t);
    return 1;
  }
  FILE *output = fopen("result.txt", "w");
  char c, str[MAX_WORD_LENGTH];
  int word_len = 0;
  while ((c = fgetc(input)) != EOF) {
    if (c == '\t' || c == '\n' || c == ' ') {
      str[word_len] = '\0';
      list_item *item = find(&hash_t, str);
      if (item != NULL) {
        fprintf(output, "%s", item->value);
      } else {
        fprintf(output, "%s", str);
      }
      word_len = 0;
      str[0] = '\0';
      fprintf(output, "%c", c);
    } else {
      str[word_len++] = c;
    }
  }

  if (word_len > 0) {
    str[word_len] = '\0';
    fprintf(output, "%s", str);
  }

  destruct_hash_table(&hash_t);
  return 0;
}