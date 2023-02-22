#include "../s21_string.h"

int s21_strcmp(const char *str1, const char *str2) {
  int result = 0;

  for (; *str1 == *str2; ++str1, ++str2)
    if (*str2 == '\0') {
      break;
    }

  result = (unsigned char)*str1 - (unsigned char)*str2;

  return result;
}