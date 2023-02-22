#include "../s21_string.h"

char* s21_strtok(char* str, const char* delim) {
  static char* buffer;
  if (str != S21_NULL) {
    buffer = str;
  }
  buffer += s21_strspn(buffer, delim);
  if (*buffer == '\0') {
    return S21_NULL;
  }
  char* const tokenBegin = buffer;
  buffer += s21_strcspn(buffer, delim);
  if (*buffer != '\0') {
    *buffer++ = '\0';
  }
  return tokenBegin;
}