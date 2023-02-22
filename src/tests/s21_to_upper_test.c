#include "./test_main.h"

START_TEST(to_upper_1) {
  char str1[16] = "allcharstoupper";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, "ALLCHARSTOUPPER");
  free(str2);
}
END_TEST

START_TEST(to_upper_2) {
  char str1[19] = "few words to upper";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, "FEW WORDS TO UPPER");
  free(str2);
}
END_TEST

START_TEST(to_upper_3) {
  char str1[1] = "";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, "");
  free(str2);
}
END_TEST

START_TEST(to_upper_4) {
  char str1[16] = "NOTHINGTOCHANGE";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, "NOTHINGTOCHANGE");
  free(str2);
}
END_TEST

START_TEST(to_upper_5) {
  char *str1 = S21_NULL;
  char *str2 = s21_to_upper(str1);
  ck_assert_ptr_eq(str2, S21_NULL);
  free(str2);
}
END_TEST

START_TEST(to_upper_6) {
  char str1[13] = "charswith123";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, "CHARSWITH123");
  free(str2);
}
END_TEST

START_TEST(to_upper_7) {
  char str1[12] = "hello\0world";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, "HELLO");
  free(str2);
}
END_TEST

START_TEST(to_upper_8) {
  char str1[10] = "\0a\0";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, "");
  free(str2);
}
END_TEST

START_TEST(to_upper_9) {
  char str1[10] = "{hello}";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, "{HELLO}");
  free(str2);
}
END_TEST

Suite *suite_s21_to_upper(void) {
  Suite *s21;
  TCase *tc21;
  s21 = suite_create("s21_TO_UPPER");
  tc21 = tcase_create("case_to_upper");
  tcase_add_test(tc21, to_upper_1);
  tcase_add_test(tc21, to_upper_2);
  tcase_add_test(tc21, to_upper_3);
  tcase_add_test(tc21, to_upper_4);
  tcase_add_test(tc21, to_upper_5);
  tcase_add_test(tc21, to_upper_6);
  tcase_add_test(tc21, to_upper_7);
  tcase_add_test(tc21, to_upper_8);
  tcase_add_test(tc21, to_upper_9);
  suite_add_tcase(s21, tc21);
  return s21;
}