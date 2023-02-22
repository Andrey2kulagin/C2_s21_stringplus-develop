#ifndef SRC_TESTS_TEST_MAIN_H_
#define SRC_TESTS_TEST_MAIN_H_

#include <check.h>
#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"

#define ARRAY_SIZE(arr) (sizeof((arr)) / sizeof((arr)[0]))

Suite *suite_s21_memchr(void);
Suite *suite_s21_memcmp(void);
Suite *suite_s21_memcpy(void);
Suite *suite_s21_memmove(void);
Suite *suite_s21_memset(void);
Suite *suite_s21_sprintf(void);
Suite *suite_s21_strcat(void);
Suite *suite_s21_strncat(void);
Suite *suite_s21_strchr(void);
Suite *suite_s21_strcmp(void);
Suite *suite_s21_strncmp(void);
Suite *suite_s21_strcpy(void);
Suite *suite_s21_strncpy(void);
Suite *suite_s21_strcspn(void);
Suite *suite_s21_strpbrk(void);
Suite *suite_s21_strerror(void);
Suite *suite_s21_strlen(void);
Suite *suite_s21_strrchr(void);
Suite *suite_s21_strspn(void);
Suite *suite_s21_strstr(void);
Suite *suite_s21_to_upper(void);
Suite *suite_s21_to_lower(void);
Suite *suite_s21_strtok(void);
Suite *suite_s21_trim(void);
Suite *suite_s21_insert(void);
#endif  //  SRC_TESTS_TEST_MAIN_H_
