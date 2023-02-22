#include "./test_main.h"

START_TEST(strstr_test1) {
  const char src[10] = "abcdababc\0";
  const char src1[10] = "dab\0";
  ck_assert_ptr_eq(s21_strstr(src, src1), strstr(src, src1));
}
END_TEST

START_TEST(strstr_test2) {
  const char src[10] = "abcdababc\0";
  const char src1[10] = "abc\0";
  ck_assert_ptr_eq(s21_strstr(src, src1), strstr(src, src1));
}
END_TEST

START_TEST(strstr_test3) {
  const char src[10] = "abcdababc\0";
  const char src1[10] = "\0";
  ck_assert_ptr_eq(s21_strstr(src, src1), strstr(src, src1));
}
END_TEST

START_TEST(strstr_test4) {
  const char src[10] = "qwer\0";
  const char src1[10] = "dab\0";
  ck_assert_ptr_eq(s21_strstr(src, src1), strstr(src, src1));
}
END_TEST

Suite *suite_s21_strstr(void) {
  Suite *s = suite_create("s21_strstr");
  TCase *tc = tcase_create("case_strstr");
  tcase_add_test(tc, strstr_test1);
  tcase_add_test(tc, strstr_test2);
  tcase_add_test(tc, strstr_test3);
  tcase_add_test(tc, strstr_test4);
  suite_add_tcase(s, tc);
  return s;
}
