#include "../s21_string.h"

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  char *buff = (char *)calloc(n, sizeof(char));
  s21_memcpy(buff, src, n);
  s21_memcpy(dest, buff, n);
  free(buff);
  return dest;
}