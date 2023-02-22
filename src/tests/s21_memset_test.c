#include "./test_main.h"

START_TEST(memset_1) {
  char str[10] = "123456789";
  ck_assert_str_eq(memset(str, 'k', 3), s21_memset(str, 'k', 3));
}
END_TEST

START_TEST(memset_2) {
  char str1[15] = "1234567890";
  char str2[15] = "5432167890";
  int c = 'q';
  int n = 10;
  s21_memset(str1, c, n);
  memset(str2, c, n);
  ck_assert_mem_eq(str1, str2, 10);
}
END_TEST

START_TEST(memset_3) {
  char str1[15] = "qweqweqweqwe";
  char str2[15] = "qweqweqweqwe";
  int c = '\0';
  int n = 5;
  s21_memset(str1, c, n);
  memset(str2, c, n);
  ck_assert_mem_eq(str1, str2, 10);
}
END_TEST

START_TEST(memset_4) {
  char str1[15] = "qweqweqweqwe";
  char str2[15] = "qweqweqweqwe";
  int c = '\n';
  int n = 5;
  s21_memset(str1, c, n);
  memset(str2, c, n);
  ck_assert_mem_eq(str1, str2, 10);
}
END_TEST

START_TEST(memset_5) {
  char s1[255] = "QWERTY";
  ck_assert_pstr_eq(memset(s1, 2, 6), s21_memset(s1, 2, 6));
}
END_TEST

Suite *suite_s21_memset(void) {
  Suite *s3;
  TCase *tc3;
  s3 = suite_create("s21_MEMSET");
  tc3 = tcase_create("case_memset");
  tcase_add_test(tc3, memset_1);
  tcase_add_test(tc3, memset_2);
  tcase_add_test(tc3, memset_3);
  tcase_add_test(tc3, memset_4);
  tcase_add_test(tc3, memset_5);
  suite_add_tcase(s3, tc3);
  return s3;
}