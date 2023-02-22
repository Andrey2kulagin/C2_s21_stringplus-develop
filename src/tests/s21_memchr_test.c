#include "./test_main.h"

START_TEST(memchr_1) {
  char *s1 = "0";
  ck_assert_pstr_eq(memchr(s1, 48, 1), s21_memchr(s1, 48, 1));
}
END_TEST

START_TEST(memchr_2) {
  char str_9[12] = "Hello world";
  ck_assert_str_eq(memchr(str_9, 'w', strlen(str_9)),
                   s21_memchr(str_9, 'w', s21_strlen(str_9)));
}
END_TEST

START_TEST(memchr_3) {
  char str_3[12] = "i am\nproger";
  ck_assert_str_eq(memchr(str_3, '\n', 6), s21_memchr(str_3, '\n', 6));
}
END_TEST

START_TEST(memchr_4) {
  char str_5[5] = " \n\0\0";
  ck_assert_str_eq(memchr(str_5, '\0', 4), s21_memchr(str_5, '\0', 4));
}
END_TEST

START_TEST(memchr_6) {
  char str_1[12] = "Hello world";
  ck_assert_str_eq(memchr(str_1, 'w', strlen(str_1)),
                   s21_memchr(str_1, 'w', s21_strlen(str_1)));
}
END_TEST

START_TEST(memchr_8) {
  char str_1[20] = "Per aspera ad astra";
  ck_assert_ptr_eq(memchr(str_1, 'p', 2), s21_memchr(str_1, 'p', 2));
}
END_TEST

START_TEST(memchr_9) {
  char str_1[4] = "a\n\0";
  ck_assert_str_eq(memchr(str_1, '\0', 4), s21_memchr(str_1, '\0', 4));
}
END_TEST

// START_TEST(memchr_10) {
//   char *s1 = "0";
//   ck_assert_pstr_eq(memchr(s1, '2', 4), s21_memchr(s1, '2', 4));
// }
// END_TEST

START_TEST(memchr_11) {
  char str_3[12] = "i am\nproger";
  ck_assert_ptr_eq(memchr(str_3, 'p', 2), s21_memchr(str_3, 'p', 2));
}
END_TEST

START_TEST(memchr_12) {
  char *s1 = "0";
  ck_assert_pstr_eq(memchr(s1, 85, 1), s21_memchr(s1, 85, 1));
}
END_TEST

START_TEST(memchr_13) {
  char str[] = "Hello w\0orld\0";
  ck_assert_pstr_eq(memchr(str, 'r', 5), s21_memchr(str, 'r', 5));
}
END_TEST

START_TEST(memchr_14) {
  char str2[] = "john.smith@microsoft.com";
  ck_assert_pstr_eq(memchr(str2, 's', 6), s21_memchr(str2, 's', 6));
}
END_TEST

START_TEST(memchr_15) {
  char str3[] = {'q', 'r', 's', 't', 'w', '\0'};
  ck_assert_pstr_eq(memchr(str3, 's', 5), s21_memchr(str3, 's', 5));
}
END_TEST

Suite *suite_s21_memchr(void) {
  Suite *s6;
  TCase *tc6;
  s6 = suite_create("s21_MEMCHR");
  tc6 = tcase_create("case_memchr");
  tcase_add_test(tc6, memchr_1);
  tcase_add_test(tc6, memchr_2);
  tcase_add_test(tc6, memchr_3);
  tcase_add_test(tc6, memchr_4);
  tcase_add_test(tc6, memchr_6);
  tcase_add_test(tc6, memchr_8);
  tcase_add_test(tc6, memchr_9);
  // tcase_add_test(tc6, memchr_10);
  tcase_add_test(tc6, memchr_11);
  tcase_add_test(tc6, memchr_12);
  tcase_add_test(tc6, memchr_13);
  tcase_add_test(tc6, memchr_14);
  tcase_add_test(tc6, memchr_15);
  suite_add_tcase(s6, tc6);
  return s6;
}