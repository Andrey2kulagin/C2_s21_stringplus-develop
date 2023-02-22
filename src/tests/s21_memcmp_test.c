#include "./test_main.h"

START_TEST(memcmp_1) {
  char str[] = "Hello World";
  char str1[] = "Hello World";
  int n = '\0';
  ck_assert_int_eq(s21_memcmp(str, str1, n), memcmp(str, str1, n));
}
END_TEST

START_TEST(memcmp_2) {
  char str[] = "Hello World";

  char str1[] = "Hello World";
  int n = 0;
  ck_assert_int_eq(s21_memcmp(str, str1, n), memcmp(str, str1, n));
}
END_TEST

START_TEST(memcmp_3) {
  char str[] = "Hello";
  char str1[] = "notequal";
  int n = 5;
  ck_assert_int_eq(s21_memcmp(str, str1, n), memcmp(str, str1, n));
}
END_TEST

START_TEST(memcmp_4) {
  char str[] = "Hello World";
  char str1[] = "";
  int n = 1;
  ck_assert_int_eq(s21_memcmp(str, str1, n), memcmp(str, str1, n));
}
END_TEST

START_TEST(memcmp_5) {
  char str[] = "Hello World";
  char str1[] = "";
  int n = 1;
  ck_assert_int_eq(s21_memcmp(str, str1, n), memcmp(str, str1, n));
}
END_TEST

START_TEST(memcmp_6) {
  char str_5[] = " \n\0\0";
  char str_6[] = " a\n\0";
  ck_assert_int_eq(memcmp(str_5, str_6, 3), s21_memcmp(str_5, str_6, 3));
}
END_TEST

START_TEST(memcmp_7) {
  char str[] = "abc";
  char str1[] = "bca";
  ck_assert_int_eq(memcmp(str, str1, 2), s21_memcmp(str, str1, 2));
}
END_TEST

START_TEST(memcmp_8) {
  char str_36[] = "Hello";
  char str_37[] = "HeLlo";
  ck_assert_int_eq(memcmp(str_36, str_37, 3), s21_memcmp(str_36, str_37, 3));
}
END_TEST

START_TEST(memcmp_9) {
  char str[] = "Per aspera ad astra";
  char str1[] = "i am\nproger";
  ck_assert_int_eq(memcmp(str, str1, 3), s21_memcmp(str, str1, 3));
}
END_TEST

START_TEST(memcmp_10) {
  char str[] = "Per aspera ad astra";
  char str1[] = "i am\nproger";
  ck_assert_int_eq(memcmp(str, str1, 0), s21_memcmp(str, str1, 0));
}
END_TEST

START_TEST(memcmp_11) {
  char str[] = "Per aspera ad astra";
  char str1[] = "i am\nproger";
  ck_assert_int_eq(memcmp(str, str1, 10), s21_memcmp(str, str1, 10));
}
END_TEST

START_TEST(memcmp_12) {
  char str[] = "Per aspera ad astra";
  char str1[] = "\0\0\0\0\0";
  ck_assert_int_eq(memcmp(str, str1, 5), s21_memcmp(str, str1, 5));
}
END_TEST

START_TEST(memcmp_13) {
  char str1[] = "t\200";
  char str2[] = "t\0";
  int n = 2;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_14) {
  char str1[] = "test\0test";
  char str2[] = "test";
  int n = 3;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_15) {
  char str1[] = "t\200";
  char str2[] = "t\n";
  int n = 2;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

// START_TEST(memcmp_16) {
//   char *s1 = "QWERTY";
//   char *s2 = "QWE";
//   ck_assert_int_eq(memcmp(s1, s2, 6), s21_memcmp(s1, s2, 6));
//   ck_assert_int_eq(memcmp(s1, s2, 4), s21_memcmp(s1, s2, 4));
// }
// END_TEST

START_TEST(memcmp_17) {
  s21_size_t n1 = 3;
  void *str1 = "LUGANO!";
  void *str2 = "LUGANO!";
  ck_assert_int_eq(memcmp(str1, str2, n1), s21_memcmp(str1, str2, n1));
}
END_TEST

START_TEST(memcmp_18) {
  s21_size_t n2 = 3;
  void *str1 = "LUGANO THE BEST!";
  void *str2 = "LU GANO OF THE BEST!!";
  ck_assert_int_eq(memcmp(str1, str2, n2), s21_memcmp(str1, str2, n2));
}
END_TEST

START_TEST(memcmp_19) {
  s21_size_t n3 = 3;
  void *str1 = " LUGANO OF THE BEST!!";
  void *str2 = "LUGANO!";
  ck_assert_int_eq(memcmp(str1, str2, n3), s21_memcmp(str1, str2, n3));
}
END_TEST

START_TEST(memcmp_30) {
  char str1[] = "1234567890\n\0";
  char str2[] = "1234567890\n\0";
  ck_assert_int_eq((s21_memcmp(str1, str2, 11) == 0),
                   (memcmp(str1, str2, 11) == 0));
}
END_TEST

START_TEST(memcmp_31) {
  char str1[15] = "1234567890\0";
  char str2[15] = "1234567890\0";
  ck_assert_int_eq(s21_memcmp(str1, str2, 11), memcmp(str1, str2, 11));
}
END_TEST

START_TEST(memcmp_32) {
  char str1[15] = "1234509876\n\0";
  char str2[15] = "1234567890\n\0";
  ck_assert_int_eq((s21_memcmp(str1, str2, 11) == 0),
                   (memcmp(str1, str2, 11) == 0));
}
END_TEST

START_TEST(memcmp_33) {
  char str1[15] = "1\n2\n3\n4\n5\n6\0";
  char str2[15] = "1\n2\n3\n5\n6\n4\0";
  ck_assert_int_eq(s21_memcmp(str1, str2, 6), memcmp(str1, str2, 6));
}
END_TEST

START_TEST(memcmp_34) {
  char str1[15] = "\ngoogle\0";
  char str2[15] = "\ngooble\0";
  ck_assert_int_eq(s21_memcmp(str1, str2, 15), memcmp(str1, str2, 15));
}
END_TEST

START_TEST(memcmp_35) {
  char str1[100] = "boobles\\//\'\0";
  char str2[100] = "boobless\\//\'\00";
  ck_assert_int_eq(s21_memcmp(str1, str2, 20), memcmp(str1, str2, 20));
}
END_TEST

START_TEST(memcmp_36) {
  char str1[100] = "boobless\\//\'\0";
  char str2[100] = "boobless\\//\'\00";
  ck_assert_int_eq(s21_memcmp(str1, str2, 50), memcmp(str1, str2, 50));
}
END_TEST

START_TEST(memcmp_37) {
  char str1[20] = "Hello World\n";
  char str2[20] = "Hello world";
  ck_assert_int_eq(s21_memcmp(str1, str2, 20), memcmp(str1, str2, 20));
}
END_TEST

START_TEST(memcmp_38) {
  char str1[20] = "Hello World\0";
  char str2[20] = "Hello World!\n\0";
  ck_assert_int_eq(s21_memcmp(str1, str2, 20), memcmp(str1, str2, 20));
}
END_TEST

START_TEST(memcmp_39) {
  char str1[100] = "\0";
  char str2[100] = "\0";
  ck_assert_int_eq(s21_memcmp(str1, str2, 4), memcmp(str1, str2, 4));
}
END_TEST

Suite *suite_s21_memcmp(void) {
  Suite *s11;
  TCase *tc11;
  s11 = suite_create("s21_MEMCMP");
  tc11 = tcase_create("case_memcmp");
  tcase_add_test(tc11, memcmp_1);
  tcase_add_test(tc11, memcmp_2);
  tcase_add_test(tc11, memcmp_3);
  tcase_add_test(tc11, memcmp_4);
  tcase_add_test(tc11, memcmp_5);
  tcase_add_test(tc11, memcmp_6);
  tcase_add_test(tc11, memcmp_7);
  tcase_add_test(tc11, memcmp_8);
  tcase_add_test(tc11, memcmp_9);
  tcase_add_test(tc11, memcmp_10);
  tcase_add_test(tc11, memcmp_11);
  tcase_add_test(tc11, memcmp_12);
  tcase_add_test(tc11, memcmp_13);
  tcase_add_test(tc11, memcmp_14);
  tcase_add_test(tc11, memcmp_15);
  // tcase_add_test(tc11, memcmp_16);
  tcase_add_test(tc11, memcmp_17);
  tcase_add_test(tc11, memcmp_18);
  tcase_add_test(tc11, memcmp_19);
  tcase_add_test(tc11, memcmp_30);
  tcase_add_test(tc11, memcmp_31);
  tcase_add_test(tc11, memcmp_32);
  tcase_add_test(tc11, memcmp_33);
  tcase_add_test(tc11, memcmp_34);
  tcase_add_test(tc11, memcmp_35);
  tcase_add_test(tc11, memcmp_36);
  tcase_add_test(tc11, memcmp_37);
  tcase_add_test(tc11, memcmp_38);
  tcase_add_test(tc11, memcmp_39);
  suite_add_tcase(s11, tc11);
  return s11;
}