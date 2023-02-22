#include "./test_main.h"

START_TEST(strcat_1) {
  char str_1[50] = "Hello";
  char str_2[50] = "Hello World";
  ck_assert_str_eq(strcat(str_1, str_2), s21_strcat(str_1, str_2));
}
END_TEST

START_TEST(strcat_2) {
  char str_1[50] = "Hello";
  char str_2[50] = "Hello World";
  ck_assert_str_eq(strcat(str_1, str_2), s21_strcat(str_1, str_2));
}
END_TEST

START_TEST(strcat_3) {
  char str_1[50] = "\0";
  char str_2[50] = "123";
  ck_assert_str_eq(strcat(str_1, str_2), s21_strcat(str_1, str_2));
}
END_TEST

START_TEST(strcat_4) {
  char str_1[50] = "\0";
  char str_2[50] = "\n\\\\\0";
  ck_assert_str_eq(strcat(str_1, str_2), s21_strcat(str_1, str_2));
}
END_TEST

START_TEST(strcat_5) {
  char str_1[50] = " 1 -";
  char str_2[50] = "\t!";
  ck_assert_str_eq(strcat(str_1, str_2), s21_strcat(str_1, str_2));
}
END_TEST

START_TEST(strcat_6) {
  char str_1[50] = "\0";
  char str_2[50] = "\0";
  ck_assert_str_eq(strcat(str_1, str_2), s21_strcat(str_1, str_2));
}
END_TEST

START_TEST(strcat_7) {
  char str_1[50] = "quas\0";
  char str_2[50] = "\nwex\t\0";
  ck_assert_str_eq(strcat(str_1, str_2), s21_strcat(str_1, str_2));
}
END_TEST

START_TEST(strcat_8) {
  char s1[255] = "QWERTY";
  char *s2 = "E";
  ck_assert_pstr_eq(strcat(s1, s2), s21_strcat(s1, s2));
}
END_TEST

Suite *suite_s21_strcat(void) {
  Suite *s16;
  TCase *tc16;
  s16 = suite_create("s21_STRCAT");
  tc16 = tcase_create("case_strcat");
  tcase_add_test(tc16, strcat_1);
  tcase_add_test(tc16, strcat_2);
  tcase_add_test(tc16, strcat_3);
  tcase_add_test(tc16, strcat_4);
  tcase_add_test(tc16, strcat_5);
  tcase_add_test(tc16, strcat_6);
  tcase_add_test(tc16, strcat_7);
  tcase_add_test(tc16, strcat_8);
  suite_add_tcase(s16, tc16);
  return s16;
}