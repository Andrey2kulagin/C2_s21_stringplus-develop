#include "./test_main.h"

START_TEST(strtok_tests_1) {
  // ++
  char str12[100] = "776832768178";
  char str23[100] = "-1213002%s";
  char str112[100] = "776832768178";
  char str123[100] = "-1213002%s";
  ck_assert_str_eq(s21_strtok(str12, str23), strtok(str112, str123));
  ck_assert_str_eq(s21_strtok(NULL, str23), strtok(NULL, str123));
  ck_assert_str_eq(s21_strtok(NULL, str23), strtok(NULL, str123));
  ck_assert_ptr_eq(s21_strtok(NULL, str23), strtok(NULL, str123));
  ck_assert_ptr_eq(s21_strtok(NULL, str23), strtok(NULL, str123));
}
END_TEST

START_TEST(strtok_tests_2) {
  // ++
  char str11[100] = "1/2/3/4";
  char str21[100] = "/";
  char str111[100] = "1/2/3/4\0";
  char str121[100] = "/\0";
  ck_assert_str_eq(s21_strtok(str11, str21), strtok(str111, str121));
  ck_assert_str_eq(s21_strtok(NULL, str21), strtok(NULL, str121));
  ck_assert_str_eq(s21_strtok(NULL, str21), strtok(NULL, str121));
  ck_assert_str_eq(s21_strtok(NULL, str21), strtok(NULL, str121));
  ck_assert_ptr_eq(s21_strtok(NULL, str21), strtok(NULL, str121));
}
END_TEST

START_TEST(strtok_tests_3) {
  // ++
  char str12[100] = "776832768178";
  char str22[100] = "";
  char str112[100] = "776832768178";
  char str122[100] = "";
  ck_assert_str_eq(s21_strtok(str12, str22), strtok(str112, str122));
  ck_assert_ptr_eq(s21_strtok(NULL, str22), strtok(NULL, str122));
  ck_assert_ptr_eq(s21_strtok(NULL, str22), strtok(NULL, str122));
}
END_TEST

Suite *suite_s21_strtok(void) {
  Suite *s = suite_create("s21_strtok");
  TCase *tc = tcase_create("case_strtok");
  tcase_add_test(tc, strtok_tests_1);
  tcase_add_test(tc, strtok_tests_2);
  tcase_add_test(tc, strtok_tests_3);
  suite_add_tcase(s, tc);
  return s;
}
