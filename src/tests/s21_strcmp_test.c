#include "./test_main.h"

START_TEST(strcmp_1) {
  char str[] = " \n\0\0";
  char str1[] = " a\n\0";
  ck_assert_int_eq(strcmp(str, str1), s21_strcmp(str, str1));
}
END_TEST

START_TEST(strcmp_2) {
  char str[] = "Techie Delight  ";
  char str1[] = "Ace the Technical Interviews";
  ck_assert_int_eq(strcmp(str, str1), s21_strcmp(str, str1));
}
END_TEST

START_TEST(strcmp_3) {
  char str[] = "Techie";
  char str1[] = "Techie";
  ck_assert_int_eq(strcmp(str, str1), s21_strcmp(str, str1));
}
END_TEST

START_TEST(strcmp_4) {
  char str[] = "Techie";
  char str1[] = "Techi";
  ck_assert_int_eq(strcmp(str, str1), s21_strcmp(str, str1));
}
END_TEST

START_TEST(strcmp_5) {
  char str[] = "Techie";
  char str1[] = "";
  ck_assert_int_eq(strcmp(str, str1), s21_strcmp(str, str1));
}
END_TEST

START_TEST(strcmp_6) {
  char str[] = "Techie";
  char str1[] = "Techia";
  ck_assert_int_eq(strcmp(str, str1), s21_strcmp(str, str1));
}
END_TEST

START_TEST(strcmp_7) {
  char str[] = "Techie";
  char str1[] = "Techis";
  ck_assert_int_eq(strcmp(str, str1), s21_strcmp(str, str1));
}
END_TEST

START_TEST(strcmp_8) {
  char str[] = "";
  char str1[] = "Techia";
  ck_assert_int_eq(strcmp(str, str1), s21_strcmp(str, str1));
}
END_TEST

START_TEST(strcmp_9) {
  char str[] = "";
  char str1[] = "";
  ck_assert_int_eq(strcmp(str, str1), s21_strcmp(str, str1));
}
END_TEST

START_TEST(strcmp_10) {
  char str[] = "HELLO PRIVET MAMA YA V TESTE";
  char str1[] = "\0";
  ck_assert_int_eq(strcmp(str, str1), s21_strcmp(str, str1));
}
END_TEST

START_TEST(strcmp_11) {
  char str[] = "\0";
  char str1[] = "\0";
  ck_assert_int_eq(strcmp(str, str1), s21_strcmp(str, str1));
}
END_TEST

START_TEST(strcmp_12) {
  char str[] = "\0";
  char str1[] = "HELLO PRIVET MAMA YA V TESTE";
  ck_assert_int_eq(strcmp(str, str1), s21_strcmp(str, str1));
}
END_TEST

START_TEST(strcmp_13) {
  char str[] = "HELLO\0";
  char str1[] = "HELLO PRIVET MAMA YA V TESTE";
  ck_assert_int_eq(strcmp(str, str1), s21_strcmp(str, str1));
}
END_TEST

START_TEST(strcmp_14) {
  char str[] = "HEL\0";
  char str1[] = "HEL \0";
  ck_assert_int_eq(strcmp(str, str1), s21_strcmp(str, str1));
}
END_TEST

START_TEST(strcmp_15) {
  char str[] = " \n\0\0";
  char str1[] = "HELO PRIVET MAMA YA V TESTE";
  ck_assert_int_eq(strcmp(str, str1), s21_strcmp(str, str1));
}
END_TEST

START_TEST(strcmp_16) {
  char str_1[10] = "\0";
  char str_7[50] = "Per aspera ad astra";
  char str_4[50] = " schhol21\0";
  char str_5[50] = " \n\0\0";
  char str_6[10] = " a\n\0";
  char str_11[] = "Hello";
  char str_12[] = "lo";
  ck_assert_int_eq(strcmp(str_1, str_7), s21_strcmp(str_1, str_7));
  ck_assert_int_eq(strcmp(str_11, str_12), s21_strcmp(str_11, str_12));
  ck_assert_int_eq(strcmp("", str_6), s21_strcmp("", str_6));
  ck_assert_int_eq(strcmp(str_4, ""), s21_strcmp(str_4, ""));
  ck_assert_int_eq(strcmp(str_5, str_6), s21_strcmp(str_5, str_6));
  ck_assert_int_eq(strcmp(str_6, str_5), s21_strcmp(str_6, str_5));
}
END_TEST

START_TEST(strcmp_17) {
  char str1[] = "t\200";
  char str2[] = "t\0";
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}
END_TEST

START_TEST(strcmp_18) {
  char str1[] = "test\0test";
  char str2[] = "test";
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}
END_TEST

START_TEST(strcmp_19) {
  char str1[] = "t\200";
  char str2[] = "t\n";
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}
END_TEST

START_TEST(strcmp_20) {
  char str1[] = "\0\0\0\0\0\0\0\0\0\0";
  char str2[] = "\0\0\0\0\0\0\0\0\0\0";
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}
END_TEST

START_TEST(strcmp_21) {
  char *s1 = "QWERTY";
  char *s2 = "E";
  ck_assert_int_eq(strcmp(s1, s2), s21_strcmp(s1, s2));
  ck_assert_int_eq(strcmp(s2, s1), s21_strcmp(s2, s1));
}
END_TEST

Suite *suite_s21_strcmp(void) {
  Suite *s12;
  TCase *tc12;
  s12 = suite_create("s21_STRCMP");
  tc12 = tcase_create("case_strcmp");
  tcase_add_test(tc12, strcmp_1);
  tcase_add_test(tc12, strcmp_2);
  tcase_add_test(tc12, strcmp_3);
  tcase_add_test(tc12, strcmp_4);
  tcase_add_test(tc12, strcmp_5);
  tcase_add_test(tc12, strcmp_6);
  tcase_add_test(tc12, strcmp_7);
  tcase_add_test(tc12, strcmp_8);
  tcase_add_test(tc12, strcmp_9);
  tcase_add_test(tc12, strcmp_10);
  tcase_add_test(tc12, strcmp_11);
  tcase_add_test(tc12, strcmp_12);
  tcase_add_test(tc12, strcmp_13);
  tcase_add_test(tc12, strcmp_14);
  tcase_add_test(tc12, strcmp_15);
  tcase_add_test(tc12, strcmp_16);
  tcase_add_test(tc12, strcmp_17);
  tcase_add_test(tc12, strcmp_18);
  tcase_add_test(tc12, strcmp_19);
  tcase_add_test(tc12, strcmp_20);
  tcase_add_test(tc12, strcmp_21);
  suite_add_tcase(s12, tc12);
  return s12;
}