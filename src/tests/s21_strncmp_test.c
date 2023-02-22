#include "./test_main.h"

START_TEST(strncmp_1) {
  char str_1[10] = "\0";
  char str_2[50] = "Per aspera ad astra";
  ck_assert_int_eq(strncmp(str_1, str_2, 0), s21_strncmp(str_1, str_2, 0));
}
END_TEST

START_TEST(strncmp_2) {
  char str_1[12] = "i am\nproger";
  char str_2[50] = " \n\0\0";
  ck_assert_int_eq(strncmp(str_1, str_2, 5), s21_strncmp(str_1, str_2, 5));
}
END_TEST

START_TEST(strncmp_3) {
  char str_1[10] = " a\n\0";
  char str_2[15] = "1234567890";
  ck_assert_int_eq(strncmp(str_1, str_2, 3), s21_strncmp(str_1, str_2, 3));
}
END_TEST

START_TEST(strncmp_4) {
  char str_1[15] = "1234975654";
  char str_2[15] = "1234567890";
  ck_assert_int_eq(strncmp(str_1, str_2, 1), s21_strncmp(str_1, str_2, 1));
}
END_TEST

START_TEST(strncmp_5) {
  char str_1[15] = "1234567890";
  char str_2[10] = "qwerty";
  ck_assert_int_eq(strncmp(str_1, str_2, 5), s21_strncmp(str_1, str_2, 5));
}
END_TEST

START_TEST(strncmp_6) {
  char s1[255] = "QWERTY";
  char s2[255] = "E";
  ck_assert_int_eq(strncmp(s1, s2, 6), s21_strncmp(s1, s2, 6));
}
END_TEST

Suite *suite_s21_strncmp(void) {
  Suite *s13;
  TCase *tc13;
  s13 = suite_create("s21_STRNCMP");
  tc13 = tcase_create("case_strncmp");
  tcase_add_test(tc13, strncmp_1);
  tcase_add_test(tc13, strncmp_2);
  tcase_add_test(tc13, strncmp_3);
  tcase_add_test(tc13, strncmp_4);
  tcase_add_test(tc13, strncmp_5);
  tcase_add_test(tc13, strncmp_6);
  suite_add_tcase(s13, tc13);
  return s13;
}