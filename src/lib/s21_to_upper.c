#include "../s21_string.h"

void* s21_to_upper(const char* str) {
  char* new_str = S21_NULL;
  if (str) {
    new_str = (char*)malloc((s21_strlen(str) + 1) * sizeof(char));
    if (new_str != S21_NULL) {
      s21_strcpy(new_str, str);
      for (char* tmp_str = new_str; *tmp_str; tmp_str++) {
        if (*tmp_str >= 'a' && *tmp_str <= 'z') {
          *tmp_str -= 32;
        }
      }
    }
  }
  return new_str;
}