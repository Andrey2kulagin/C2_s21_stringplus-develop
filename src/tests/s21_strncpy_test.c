#include "./test_main.h"

// START_TEST(strncpy_test1) {
//   const char src[10] = "qwer123\0";
//   char dest[10];
//   char s21_dest[10];
//   s21_strncpy(s21_dest, src, 3);
//   strncpy(dest, src, 3);
//   ck_assert_str_eq(dest, s21_dest);
// }
// END_TEST

START_TEST(strncpy_test2) {
  const char src[20] = "qwer123\0";
  char dest[20] = "/0";
  char s21_dest[20] = "/0";
  s21_strncpy(s21_dest, src, 19);
  strncpy(dest, src, 19);
  ck_assert_str_eq(dest, s21_dest);
}
END_TEST

START_TEST(strncpy_test3) {
  const char src[10] = "qwer123\0";
  char dest[20] = "/0";
  char s21_dest[20] = "/0";
  s21_strncpy(s21_dest, src, 19);
  strncpy(dest, src, 19);
  ck_assert_str_eq(dest, s21_dest);
}
END_TEST

// START_TEST(strncpy_test4) {
//   const char src[10] = "qwer123";
//   char dest[10];
//   char s21_dest[10];
//   s21_strncpy(s21_dest, src, 3);
//   strncpy(dest, src, 3);
//   ck_assert_str_eq(dest, s21_dest);
// }
// END_TEST

START_TEST(strncpy_test5) {
  const char src[20] = "qwer123";
  char dest[20] = "/0";
  char s21_dest[20] = "/0";
  s21_strncpy(s21_dest, src, 19);
  strncpy(dest, src, 19);
  ck_assert_str_eq(dest, s21_dest);
}
END_TEST

START_TEST(strncpy_test6) {
  const char src[10] = "qwer123";
  char dest[20] = "/0";
  char s21_dest[20] = "/0";
  s21_strncpy(s21_dest, src, 19);
  strncpy(dest, src, 19);
  ck_assert_str_eq(dest, s21_dest);
}
END_TEST

START_TEST(strncpy_test7) {
  const char src[7] = "qwer123";
  char dest[20] = "/0";
  char s21_dest[20] = "/0";
  s21_strncpy(s21_dest, src, 19);
  strncpy(dest, src, 19);
  ck_assert_str_eq(dest, s21_dest);
}
END_TEST

Suite *suite_s21_strncpy(void) {
  Suite *s = suite_create("s21_strncpy");
  TCase *tc = tcase_create("case_strncpy");
  // tcase_add_test(tc, strncpy_test1);
  tcase_add_test(tc, strncpy_test2);
  tcase_add_test(tc, strncpy_test3);
  // tcase_add_test(tc, strncpy_test4);
  tcase_add_test(tc, strncpy_test5);
  tcase_add_test(tc, strncpy_test6);
  tcase_add_test(tc, strncpy_test7);
  suite_add_tcase(s, tc);
  return s;
}
