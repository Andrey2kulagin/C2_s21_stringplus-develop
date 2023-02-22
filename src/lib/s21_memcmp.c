#include "../s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  s21_size_t i = 0;
  int result = 0;
  while (i < n) {
    if (*(unsigned char *)str1 != *(unsigned char *)str2) {
      result = *(unsigned char *)str1 - *(unsigned char *)str2;
      i = n;
    }

    str1++;
    str2++;
    i++;
  }

  return result;
}
