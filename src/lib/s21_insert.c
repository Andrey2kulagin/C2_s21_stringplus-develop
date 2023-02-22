#include "../s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *res = S21_NULL;
  if (src && str && start_index) {
    if (start_index > 0 && start_index <= s21_strlen(src)) {
      res =
          (char *)calloc(s21_strlen(src) + s21_strlen(str) + 19, sizeof(char));
      if (res) {
        s21_strncpy(res, src, start_index);  // memcpy dest void
        s21_strcat(res, str);
        s21_strcat(res, src + start_index);
      }
    }
  }
  return res;
}
