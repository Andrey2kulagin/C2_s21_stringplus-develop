#include "./test_main.h"

START_TEST(insert_1) {
  char *src = "KOLOBOK123";
  char *str = "sec";
  int n = 5;
  char *res = (char *)s21_insert(src, str, n);
  ck_assert_str_eq(res, "KOLOBsecOK123");
  free(res);
}
END_TEST

START_TEST(insert_2) {
  char *src = "KOLOBOK123";
  char *str = "sec";
  int n = 20;
  char *res = (char *)s21_insert(src, str, n);
  ck_assert_pstr_eq(res, NULL);
  free(res);
}
END_TEST

Suite *suite_s21_insert(void) {
  Suite *s24;
  TCase *tc24;
  s24 = suite_create("s21_INSERT");
  tc24 = tcase_create("case_INSERT");
  tcase_add_test(tc24, insert_1);
  tcase_add_test(tc24, insert_2);
  suite_add_tcase(s24, tc24);
  return s24;
}
