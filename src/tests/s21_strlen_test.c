#include "./test_main.h"

START_TEST(strlen_test1) {
  const char str1[10] = "qwer123\0";
  ck_assert_int_eq(s21_strlen(str1), strlen(str1));
}
END_TEST

START_TEST(strlen_test2) {
  const char str1[20] = "qwer123\0asdad";
  ck_assert_int_eq(s21_strlen(str1), strlen(str1));
}
END_TEST

START_TEST(strlen_test3) {
  const char str1[10] = "qwer123";
  ck_assert_int_eq(s21_strlen(str1), strlen(str1));
}
END_TEST

START_TEST(strlen_test4) {
  const char str1[10] = "\0qwer";
  ck_assert_int_eq(s21_strlen(str1), strlen(str1));
}
END_TEST

START_TEST(strlen_test5) {
  const char str1[10] = "";
  ck_assert_int_eq(s21_strlen(str1), strlen(str1));
}
END_TEST

Suite *suite_s21_strlen(void) {
  Suite *s = suite_create("s21_strlen");
  TCase *tc = tcase_create("case_strlen");
  tcase_add_test(tc, strlen_test1);
  tcase_add_test(tc, strlen_test2);
  tcase_add_test(tc, strlen_test3);
  tcase_add_test(tc, strlen_test4);
  tcase_add_test(tc, strlen_test5);
  suite_add_tcase(s, tc);
  return s;
}
