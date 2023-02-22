#include "../s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  char *new_str = S21_NULL;
  if (src && trim_chars) {
    char *first_str = (char *)src;
    char *end_str = (char *)src + s21_strlen(src);
    for (; *first_str && s21_strchr(trim_chars, *first_str); first_str++)
      ;
    for (; end_str != first_str && s21_strchr(trim_chars, *(end_str - 1));
         end_str--)
      ;
    new_str = (char *)malloc((end_str - first_str + 5) * sizeof(char));
    if (new_str) {
      s21_strncpy(new_str, first_str, end_str - first_str);
      *(new_str + (end_str - first_str)) = '\0';
    }
  }
  return new_str;
}
