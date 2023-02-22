#include "../s21_string.h"

char *s21_strchr(const char *str, int ch) {
  char *pointer = S21_NULL;
  int i = 0;
  while (str[i] != '\0' && str[i] != ch) {
    i++;
  }
  if (str[i] == ch) {
    pointer = (char *)str + i;
  }
  return pointer;
}
