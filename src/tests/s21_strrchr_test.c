#include "./test_main.h"

START_TEST(strrchr_test1) {
  const char src[10] = "qwer123r\0";
  ck_assert_ptr_eq(s21_strrchr(src, 'r'), strrchr(src, 'r'));
}
END_TEST

START_TEST(strrchr_test2) {
  const char src[10] = "qwer123r\0";
  ck_assert_ptr_eq(s21_strrchr(src, 'l'), strrchr(src, 'l'));
}
END_TEST

START_TEST(strrchr_test3) {
  const char src[10] = "qwer123r\0";
  ck_assert_ptr_eq(s21_strrchr(src, '\0'), strrchr(src, '\0'));
}
END_TEST

START_TEST(strrchr_test4) {
  const char src[10] = "qwer123r\0r";
  ck_assert_ptr_eq(s21_strrchr(src, 'r'), strrchr(src, 'r'));
}
END_TEST

START_TEST(strrchr_test5) {
  const char src[10] = "qwe123\0r";
  ck_assert_ptr_eq(s21_strrchr(src, 'r'), strrchr(src, 'r'));
}
END_TEST

Suite *suite_s21_strrchr(void) {
  Suite *s = suite_create("s21_strrchr");
  TCase *tc = tcase_create("case_strrchr");
  tcase_add_test(tc, strrchr_test1);
  tcase_add_test(tc, strrchr_test2);
  tcase_add_test(tc, strrchr_test3);
  tcase_add_test(tc, strrchr_test4);
  tcase_add_test(tc, strrchr_test5);
  suite_add_tcase(s, tc);
  return s;
}
