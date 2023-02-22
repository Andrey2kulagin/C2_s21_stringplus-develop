#include "./test_main.h"

START_TEST(trim_1) {
  char *str1 = "Hello World";
  char *str2 = "H";
  char *str3 = (char *)s21_trim(str1, str2);
  ck_assert_str_eq(str3, "ello World");
  free(str3);
}
END_TEST

START_TEST(trim_2) {
  char *str1 = "Hello World";
  char *str2 = "Hedl";
  char *str3 = (char *)s21_trim(str1, str2);
  ck_assert_str_eq(str3, "o Wor");
  free(str3);
}
END_TEST

START_TEST(trim_3) {
  char *str1 = "";
  char *str2 = "";
  char *str3 = (char *)s21_trim(str1, str2);
  ck_assert_str_eq(str3, "");
  free(str3);
}
END_TEST

START_TEST(trim_4) {
  char *str = "empty";
  char *str2 = "empty";
  char *str3 = (char *)s21_trim(str, str2);
  ck_assert_str_eq(str3, "");
  free(str3);
}
END_TEST

START_TEST(trim_5) {
  char *str = S21_NULL;
  char *str2 = S21_NULL;
  char *str3 = (char *)s21_trim(str, str2);
  ck_assert_ptr_eq(str3, S21_NULL);
  free(str3);
}
END_TEST

START_TEST(trim_6) {
  char *str = "";
  char *str2 = S21_NULL;
  char *str3 = (char *)s21_trim(str, str2);
  ck_assert_ptr_eq(str3, S21_NULL);
  free(str3);
}
END_TEST

START_TEST(trim_7) {
  char *str = S21_NULL;
  char *str2 = "          ";
  char *str3 = (char *)s21_trim(str, str2);
  ck_assert_ptr_eq(str3, S21_NULL);
  free(str3);
}
END_TEST

START_TEST(trim_8) {
  char *str = "empty";
  char *str2 = "t";
  char *str3 = (char *)s21_trim(str, str2);
  ck_assert_str_ne(str3, "em");
  free(str3);
}
END_TEST

Suite *suite_s21_trim(void) {
  Suite *s23;
  TCase *tc23;
  s23 = suite_create("s21_TRIM");
  tc23 = tcase_create("case_TRIM");
  tcase_add_test(tc23, trim_1);
  tcase_add_test(tc23, trim_2);
  tcase_add_test(tc23, trim_3);
  tcase_add_test(tc23, trim_4);
  tcase_add_test(tc23, trim_5);
  tcase_add_test(tc23, trim_6);
  tcase_add_test(tc23, trim_7);
  tcase_add_test(tc23, trim_8);
  suite_add_tcase(s23, tc23);
  return s23;
}