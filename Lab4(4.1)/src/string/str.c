#include "str.h"

unsigned int str_len(const char *str) {
  unsigned int size = 0;
  while (str[size] != '\0') {
    size++;
  }
  return size;
}

int str_cmp(const char *s1, const char *s2) {
  int i = 0, j = 0;
  while (s1[i] != '\0' && s2[j] != '\0') {
    if (s1[i] < s2[j]) {
      return -1;
    } else if (s1[i] > s2[j]) {
      return 1;
    }
    i++;
    j++;
  }
  return s1[i] - s2[j];
}

void str_cpy(char *s, const char *p){
  int i = 0;
  while (p[i] != '\0'){
    s[i] = p[i];
    i++;
  }
  s[i] = '\0';
}