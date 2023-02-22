#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdarg.h>
#define S21_NULL ((void *)0)

typedef long unsigned s21_size_t;


struct S21_sprintf_param {
  char specifier;
  char flag[10]; 
  int width;
  int precision;
  char length;
  char *preceding_str;
};
void *s21_memchr(const void *arr, int c, s21_size_t n);
void *s21_memmove(void *dest, const void *src, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strchr(const char *str1, int ch);
char *s21_strcat(char *dest, const char *src);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strcpy(char *dest, const char *src);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
int s21_strcmp(const char *str1, const char *str2);
char *list_err(int begin, int end, int errnum, char str[]);
s21_size_t s21_strlen(const char *str);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
s21_size_t s21_strspn(const char *str1, const char *str2);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);
void *s21_to_upper(const char *str);
void *s21_to_lower(const char* str);
void *s21_trim(const char *src, const char *trim_chars);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
const char *parser_used_preceding_str(const char *format, char *preceding_str,
                                      char *used_str);
void set_end(char *preceding_str, int buffer_index);
void set_empty_str(char *preceding_str, char *used_str);
void structuring_str(char *preceding_str, char *used_str,
                     struct S21_sprintf_param *cure_param);
int set_flags(char format, struct S21_sprintf_param *cure_param,
              int *used_str_index);
int set_precision(char *used_str, int *used_str_index,
                  struct S21_sprintf_param *cure_param);
void get_int_str(char *used_str, char *int_str, int *used_str_index);
int char_to_int(char *int_str);
void struct_init(struct S21_sprintf_param *cure_param);
int set_width(char *used_str, int *used_str_index,
              struct S21_sprintf_param *cure_param);
int set_length(char *used_str, int *used_str_index,
               struct S21_sprintf_param *cure_param);
int s21_sprintf(char *str, const char *format, ...);
void sprintf_logic(va_list *ap, struct S21_sprintf_param cure_param, char *str);
void c_to_string(char *str, struct S21_sprintf_param cure_param, char c);
void base_int_to_str(char *str, long int number, struct S21_sprintf_param cure_param);
void reverse_str(char *str);
void base_int_to_str_with_flags(char *base_int_str,
                                char *base_str_with_params,
                                struct S21_sprintf_param cure_param, long int a);
void set_precision_or_width_to_int_str(int precision_or_weight,
                                       char *base_int_str,
                                       char *base_str_with_params,
                                       char sign);
void float_to_str(char *str, double number, struct S21_sprintf_param cure_param);
void set_int_precision(int precision, char *base_int_str);
void set_sign_base_int_str(char sign, char *base_int_str);
void set_base_float_str_with_param(char *base_float_str_with_params,char *base_float_str, double number, struct S21_sprintf_param cure_param);
void set_string_with_params_str(char* input_str,char* base_string_str_with_params, struct S21_sprintf_param cure_param);
void del_first_simb(char *buffer_after_point);
void di_logic(va_list *ap, struct S21_sprintf_param cure_param, char *str);
void c_logic(va_list *ap, struct S21_sprintf_param cure_param, char *str);
void u_logic(va_list *ap, struct S21_sprintf_param cure_param, char *str);
void f_logic(va_list *ap, struct S21_sprintf_param cure_param, char *str);
void s_logic(va_list *ap, struct S21_sprintf_param cure_param, char *str);
void is_not_closed_perc(int end_flag, char*used_str,  char*preceding_str, int * used_str_index, int *preceding_str_index);
void set_sign(char*sign,long int number,  struct S21_sprintf_param cure_param);

#endif  // SRC_S21_STRING_H_
