#include "./test_main.h"

START_TEST(strpbrk_test1) {
  const char src[10] = "qwer123";
  const char src1[20] = "asdfqssaad\0";
  ck_assert_ptr_eq(s21_strpbrk(src, src1), strpbrk(src, src1));
}
END_TEST

START_TEST(strpbrk_test2) {
  const char src[10] = "qwer123";
  const char src1[20] = "w\0";
  ck_assert_ptr_eq(s21_strpbrk(src, src1), strpbrk(src, src1));
}
END_TEST

START_TEST(strpbrk_test3) {
  const char src[10] = "qwer123";
  const char src1[20] = "\0";
  ck_assert_ptr_eq(s21_strpbrk(src, src1), strpbrk(src, src1));
}
END_TEST

START_TEST(strpbrk_test4) {
  const char src[10] = "qwer123";
  const char src1[20] = "l\0";
  ck_assert_ptr_eq(s21_strpbrk(src, src1), strpbrk(src, src1));
}
END_TEST

Suite *suite_s21_strpbrk(void) {
  Suite *s = suite_create("s21_strpbrk");
  TCase *tc = tcase_create("case_strpbrk");
  tcase_add_test(tc, strpbrk_test1);
  tcase_add_test(tc, strpbrk_test2);
  tcase_add_test(tc, strpbrk_test3);
  tcase_add_test(tc, strpbrk_test4);
  suite_add_tcase(s, tc);
  return s;
}
