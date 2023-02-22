#include "../s21_string.h"

void *s21_memchr(const void *arr, int sym, s21_size_t n) {
  void *result = S21_NULL;

  for (s21_size_t i = 0; i < n; i++) {
    if (*(unsigned char *)(arr + i) == sym) {
      result = (void *)(arr + i);
      break;
    }
  }
  return result;
}
