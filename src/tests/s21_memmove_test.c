#include "./test_main.h"

START_TEST(memmove_1) {
  char str[11] = "1234567890";
  ck_assert_str_eq(memmove(str + 4, str + 3, 3),
                   s21_memmove(str + 4, str + 3, 3));
}
END_TEST

START_TEST(memmove_2) {
  char str[11] = "321qwerty";
  ck_assert_str_eq(memmove(str + 4, str + 3, 0),
                   s21_memmove(str + 4, str + 3, 0));
}
END_TEST

START_TEST(memmove_3) {
  char str_1[50] = " schhol21\0";
  char str_2[12] = "i am\nproger";
  ck_assert_str_eq(memmove(str_1, str_2, 10), s21_memmove(str_1, str_2, 10));
}
END_TEST

START_TEST(memmove_4) {
  char str_1[50] = " schhol21\0";
  char str_2[12] = "s_21\n\t";
  ck_assert_str_eq(memmove(str_1, str_2, 0), s21_memmove(str_1, str_2, 0));
}
END_TEST

START_TEST(memmove_5) {
  char str_1[11] = "1234567890";
  char str_2[50] = " \n\0\0";
  ck_assert_str_eq(memmove(str_1, str_2, 2), s21_memmove(str_1, str_2, 2));
}
END_TEST

START_TEST(memmove_6) {
  char str_1[10] = " a\n\0";
  char str_2[10] = "\0";
  ck_assert_str_eq(memmove(str_1, str_2, 2), s21_memmove(str_1, str_2, 2));
}
END_TEST

START_TEST(memmove_7) {
  char str_1[10] = "t\n\f\t";
  char str_2[10] = "e5_=\n";
  ck_assert_str_eq(s21_memmove(str_1 + 2, str_2 + 2, 3),
                   memmove(str_1 + 2, str_2 + 2, 3));
}
END_TEST

START_TEST(memmove_8) {
  char str_1[15] = "ysbsdfn__--568\0";
  char str_3[10] = "lock -l";
  ck_assert_str_eq(s21_memmove(str_1, str_3, 6), memmove(str_1, str_3, 0));
}
END_TEST

START_TEST(memmove_9) {
  char str_1[10] = "0";
  char str_3[10] = "\0";
  ck_assert_str_eq(s21_memmove(str_1, str_3, 8), memmove(str_1, str_3, 10));
}
END_TEST

START_TEST(memmove_10) {
  char str_1[10] = "string(58)";
  char str_3[10] = "978=\0";
  ck_assert_str_eq(s21_memmove(str_1, str_3, 10), memmove(str_1, str_3, 10));
}
END_TEST

START_TEST(memmove_11) {
  char str_1[11] = "1234567890";
  char str_2[11] = "1234567890";
  char str_4[12] = "i am\nproger";
  char str_3[50] = " schhol21\0";
  char str_5[50] = " \n\0\0";
  char str_6[10] = " a\n\0";
  char str_7[10] = "\0";
  ck_assert_str_eq(memmove(str_1 + 4, str_1 + 3, 3),
                   s21_memmove(str_1 + 4, str_1 + 3, 3));
  ck_assert_str_eq(memmove(str_2 + 4, str_2 + 3, 0),
                   s21_memmove(str_2 + 4, str_2 + 3, 0));
  ck_assert_str_eq(memmove(str_3, str_4, 10), s21_memmove(str_3, str_4, 10));
  ck_assert_str_eq(memmove(str_3, str_4, 0), s21_memmove(str_3, str_4, 0));
  ck_assert_str_eq(memmove(str_2, str_5, 2), s21_memmove(str_2, str_5, 2));
  ck_assert_str_eq(memmove(str_6, str_7, 2), s21_memmove(str_6, str_7, 2));
}
END_TEST

START_TEST(memmove_12) {
  char s1[255] = "QWERTY";
  char s2[255] = "E";
  ck_assert_pstr_eq(memmove(s1, s2, 6), s21_memmove(s1, s2, 6));
  ck_assert_pstr_eq(memmove(s2, s1, 6), s21_memmove(s2, s1, 6));
  ck_assert_pstr_eq(memmove(s1, s1, 6), s21_memmove(s1, s1, 6));
}
END_TEST

Suite *suite_s21_memmove(void) {
  Suite *s2;
  TCase *tc2;
  s2 = suite_create("s21_MEMMOVE");
  tc2 = tcase_create("case_memmove");
  tcase_add_test(tc2, memmove_1);
  tcase_add_test(tc2, memmove_2);
  tcase_add_test(tc2, memmove_3);
  tcase_add_test(tc2, memmove_4);
  tcase_add_test(tc2, memmove_5);
  tcase_add_test(tc2, memmove_6);
  tcase_add_test(tc2, memmove_7);
  tcase_add_test(tc2, memmove_8);
  tcase_add_test(tc2, memmove_9);
  tcase_add_test(tc2, memmove_10);
  tcase_add_test(tc2, memmove_11);
  tcase_add_test(tc2, memmove_12);
  suite_add_tcase(s2, tc2);
  return s2;
}