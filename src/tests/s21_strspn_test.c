#include "./test_main.h"

START_TEST(strspn_test1) {
  const char str1[10] = "qwer123\0";
  const char str2[10] = "qwer123\0";
  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
}
END_TEST

START_TEST(strspn_test2) {
  const char str1[10] = "qwer123\0";
  const char str2[10] = "reqw321\0";
  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
}
END_TEST

START_TEST(strspn_test3) {
  const char str1[10] = "qwer123\0";
  const char str2[20] = "ahsdajdqwer123\0";
  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
}
END_TEST

START_TEST(strspn_test4) {
  const char str1[10] = "\0";
  const char str2[10] = "\0";
  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
}
END_TEST

START_TEST(strspn_test5) {
  const char str1[10] = "\0";
  const char str2[10] = "qwer1234\0";
  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
}
END_TEST

Suite *suite_s21_strspn(void) {
  Suite *s = suite_create("s21_strspn");
  TCase *tc = tcase_create("case_strspn");
  tcase_add_test(tc, strspn_test1);
  tcase_add_test(tc, strspn_test2);
  tcase_add_test(tc, strspn_test3);
  tcase_add_test(tc, strspn_test4);
  tcase_add_test(tc, strspn_test5);
  suite_add_tcase(s, tc);
  return s;
}
