#include "../s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int result = 0;
  while (n--) {
    if (*str1 != *str2) {
      result = *str1 - *str2;
    } else {
      ++str1;
      ++str2;
    }
  }
  return result;
}