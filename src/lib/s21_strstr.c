#include "../s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  char *result = S21_NULL;
  int i = 0;
  int needle_len = s21_strlen(needle);
  while (haystack[i] != '\0' && result == S21_NULL) {
    int j = 0;
    while (haystack[i + j] == needle[j] && j < needle_len) {
      j++;
    }
    if (j == needle_len) {
      result = (char *)(haystack + i);
    }
    i++;
  }
  return result;
}