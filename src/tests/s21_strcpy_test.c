#include "./test_main.h"

START_TEST(strcpy_test1) {
  const char src[10] = "qwer123";
  char dest[10];
  char s21_dest[10];
  s21_strcpy(s21_dest, src);
  strcpy(dest, src);
  ck_assert_str_eq(dest, s21_dest);
}
END_TEST

START_TEST(strcpy_test2) {
  const char src[10] = "\0";
  char dest[10];
  char s21_dest[10];
  s21_strcpy(s21_dest, src);
  strcpy(dest, src);
  ck_assert_str_eq(dest, s21_dest);
}
END_TEST

START_TEST(strcpy_test3) {
  const char src[5] = "qwe\0";
  char dest[10];
  char s21_dest[10];
  s21_strcpy(s21_dest, src);
  strcpy(dest, src);
  ck_assert_str_eq(dest, s21_dest);
}
END_TEST

Suite *suite_s21_strcpy(void) {
  Suite *s = suite_create("s21_strcpy");
  TCase *tc = tcase_create("test_strcpy");
  tcase_add_test(tc, strcpy_test1);
  tcase_add_test(tc, strcpy_test2);
  tcase_add_test(tc, strcpy_test3);
  suite_add_tcase(s, tc);
  return s;
}
