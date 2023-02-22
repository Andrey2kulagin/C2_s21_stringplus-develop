#include "./test_main.h"

START_TEST(strcspn_1) {
  char str[] = "23476";
  char str1[] = "234";
  ck_assert_int_eq(strcspn(str, str1), s21_strcspn(str, str1));
}
END_TEST

START_TEST(strcspn_2) {
  char str[] = "dg234asfd76";
  char str1[] = "23dfgh4";
  ck_assert_int_eq(strcspn(str, str1), s21_strcspn(str, str1));
}
END_TEST

START_TEST(strcspn_3) {
  char str[] = "Hello world\0dg234asfd76";
  char str1[] = "";
  ck_assert_int_eq(strcspn(str, str1), s21_strcspn(str, str1));
}
END_TEST

START_TEST(strcspn_4) {
  char str[] = "Hello world\0dg234asfd76";
  char str1[] = "\0";
  ck_assert_int_eq(strcspn(str, str1), s21_strcspn(str, str1));
}
END_TEST

START_TEST(strcspn_5) {
  char str[] = "Hello world\0dg234asfd76";
  char str1[] = " H";
  ck_assert_int_eq(strcspn(str, str1), s21_strcspn(str, str1));
}
END_TEST

START_TEST(strcspn_6) {
  char str[] = "Hello world\n\0dg234asfd76";
  char str1[] = "H";
  ck_assert_int_eq(strcspn(str, str1), s21_strcspn(str, str1));
}
END_TEST

START_TEST(strcspn_7) {
  char str[] = "Hello world\n\0dg234asfd76";
  char str1[] = " ";
  ck_assert_int_eq(strcspn(str, str1), s21_strcspn(str, str1));
}
END_TEST

START_TEST(strcspn_8) {
  char s1[] = "QWERTY";
  char s2[] = "E";
  char s3[] = "MFE";
  char s4[] = "";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
  ck_assert_int_eq(strcspn(s2, s1), s21_strcspn(s2, s1));
  ck_assert_int_eq(strcspn(s1, s1), s21_strcspn(s1, s1));
  ck_assert_int_eq(strcspn(s1, s3), s21_strcspn(s1, s3));
  ck_assert_int_eq(strcspn(s1, s4), s21_strcspn(s1, s4));
  ck_assert_int_eq(strcspn(s4, s1), s21_strcspn(s4, s1));
}
END_TEST

Suite *suite_s21_strcspn(void) {
  Suite *s20;
  TCase *tc20;
  s20 = suite_create("s21_STRCSPN");
  tc20 = tcase_create("case_strcspn");
  tcase_add_test(tc20, strcspn_1);
  tcase_add_test(tc20, strcspn_2);
  tcase_add_test(tc20, strcspn_3);
  tcase_add_test(tc20, strcspn_4);
  tcase_add_test(tc20, strcspn_5);
  tcase_add_test(tc20, strcspn_6);
  tcase_add_test(tc20, strcspn_7);
  tcase_add_test(tc20, strcspn_8);
  suite_add_tcase(s20, tc20);
  return s20;
}