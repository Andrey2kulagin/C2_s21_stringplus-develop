#include "./test_main.h"

START_TEST(strchr_1) {
  char str[] = "Hello world";
  int c = 3;
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(strchr_2) {
  char str[] = "Hello world\0";
  int c = 5;
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(strchr_3) {
  char str[] = "Hello world";
  int c = 12;
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(strchr_4) {
  char str[] = "Hello world";
  int c = '\0';
  ck_assert_str_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(strchr_5) {
  char str[] = "";
  int c = 0;
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(strchr_6) {
  char str[] = "a\n\0";
  int c = 'a';
  ck_assert_str_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(strchr_7) {
  char str[] = "aaaaaaaaaaaaaaaaaaa";
  int c = 'b';
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(strchr_8) {
  char *s1 = "QWERTY";
  char s2 = 'E';
  ck_assert_pstr_eq(strchr(s1, s2), s21_strchr(s1, s2));
}
END_TEST

Suite *suite_s21_strchr(void) {
  Suite *s7;
  TCase *tc7;
  s7 = suite_create("s21_STRCHR");
  tc7 = tcase_create("case_strchr");
  tcase_add_test(tc7, strchr_1);
  tcase_add_test(tc7, strchr_2);
  tcase_add_test(tc7, strchr_3);
  tcase_add_test(tc7, strchr_4);
  tcase_add_test(tc7, strchr_5);
  tcase_add_test(tc7, strchr_6);
  tcase_add_test(tc7, strchr_7);
  tcase_add_test(tc7, strchr_8);
  suite_add_tcase(s7, tc7);
  return s7;
}