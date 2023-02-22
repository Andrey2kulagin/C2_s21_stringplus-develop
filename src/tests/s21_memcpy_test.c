#include "./test_main.h"

START_TEST(memcpy_1) {
  char str_5[3] = "a\n\0";
  char str_6[3] = "\0";
  ck_assert_str_eq(memcpy(str_5, str_6, 2), s21_memcpy(str_5, str_6, 2));
}
END_TEST

START_TEST(memcpy_2) {
  char str_1[] = "\0";
  char str_2[] = " ";
  ck_assert_str_eq(memcpy(str_1, str_2, 2), s21_memcpy(str_1, str_2, 1));
}
END_TEST

START_TEST(memcpy_3) {
  char str_1[] = "copy_! ";
  char str_2[] = "n66";
  ck_assert_str_eq(memcpy(str_1, str_2, 2), s21_memcpy(str_1, str_2, 5));
}
END_TEST

START_TEST(memcpy_4) {
  char str_1[] = "\n/n";
  char str_2[] = "-55";
  ck_assert_str_eq(memcpy(str_1, str_2, 2), s21_memcpy(str_1, str_2, 5));
}
END_TEST

START_TEST(memcpy_5) {
  char str_1[] = "5656";
  char str_2[] = "\0\f";
  ck_assert_str_eq(memcpy(str_1, str_2, 2), s21_memcpy(str_1, str_2, 5));
}
END_TEST

START_TEST(memcpy_6) {
  char str_1[] = "%hf*-5";
  char str_2[] = "\0\f";
  ck_assert_str_eq(memcpy(str_1, str_2, 2), s21_memcpy(str_1, str_2, 5));
}
END_TEST

START_TEST(memcpy_7) {
  char s1[255] = "QWERTY";
  char s2[255] = "E";
  ck_assert_pstr_eq(memcpy(s1, s2, 6), s21_memcpy(s1, s2, 6));
}
END_TEST

Suite *suite_s21_memcpy(void) {
  Suite *s1;
  TCase *tc1;
  s1 = suite_create("s21_MEMCPY");
  tc1 = tcase_create("case_memcpy");
  tcase_add_test(tc1, memcpy_1);
  tcase_add_test(tc1, memcpy_2);
  tcase_add_test(tc1, memcpy_3);
  tcase_add_test(tc1, memcpy_4);
  tcase_add_test(tc1, memcpy_5);
  tcase_add_test(tc1, memcpy_6);
  tcase_add_test(tc1, memcpy_7);
  suite_add_tcase(s1, tc1);
  return s1;
}