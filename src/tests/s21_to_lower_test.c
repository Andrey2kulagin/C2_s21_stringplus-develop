#include "./test_main.h"

START_TEST(to_lower_1) {
  char str1[16] = "ALLCHARSTOUPPER";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "allcharstoupper");
  free(str2);
}
END_TEST

START_TEST(to_lower_2) {
  char str1[19] = "FEW WORDS TO LOWER";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "few words to lower");
  free(str2);
}
END_TEST

START_TEST(to_lower_3) {
  char str1[1] = "";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "");
  free(str2);
}
END_TEST

START_TEST(to_lower_4) {
  char str1[16] = "nothingtochange";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "nothingtochange");
  free(str2);
}
END_TEST

START_TEST(to_lower_5) {
  char *str1 = S21_NULL;
  char *str2 = s21_to_lower(str1);
  ck_assert_ptr_eq(str2, S21_NULL);
  free(str2);
}
END_TEST

START_TEST(to_lower_6) {
  char str1[13] = "CHARSWITH123";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "charswith123");
  free(str2);
}
END_TEST

START_TEST(to_lower_7) {
  char str1[12] = "HELLO\0WORLD";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "hello");
  free(str2);
}
END_TEST

START_TEST(to_lower_8) {
  char str1[10] = "\0A\0";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "");
  free(str2);
}
END_TEST

Suite *suite_s21_to_lower(void) {
  Suite *s22;
  TCase *tc22;
  s22 = suite_create("s21_TO_LOWER");
  tc22 = tcase_create("case_to_lower");
  tcase_add_test(tc22, to_lower_1);
  tcase_add_test(tc22, to_lower_2);
  tcase_add_test(tc22, to_lower_3);
  tcase_add_test(tc22, to_lower_4);
  tcase_add_test(tc22, to_lower_5);
  tcase_add_test(tc22, to_lower_6);
  tcase_add_test(tc22, to_lower_7);
  tcase_add_test(tc22, to_lower_8);
  suite_add_tcase(s22, tc22);
  return s22;
}