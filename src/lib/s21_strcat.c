#include "../s21_string.h"

char *s21_strcat(char *dest, const char *src) {
  s21_size_t size = s21_strlen(dest);
  int i = 0;
  for (; *(src + i) != '\0'; i++) {
    *(dest + size + i) = *(src + i);
  }
  *(dest + size + i) = '\0';
  return dest;
}
