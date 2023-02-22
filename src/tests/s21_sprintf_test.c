#include "./test_main.h"

START_TEST(test_no_args) {
  char result[20];
  char assert[20];
  s21_sprintf(result, "Hello, world!");
  sprintf(assert, "Hello, world!");
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(sprintf_D_0) {
  char our[20];
  char original[20];
  s21_sprintf(our, " %d%d%d%d", -4, 8, 15, 16);
  sprintf(original, " %d%d%d%d", -4, 8, 15, 16);
  ck_assert_str_eq(our, original);
}
END_TEST

START_TEST(sprintf_D_1) {
  char our[100];
  char original[100];
  s21_sprintf(our, "|%d|", 555);
  sprintf(original, "|%d|", 555);
  ck_assert_str_eq(our, original);
}
END_TEST

START_TEST(D_11) {
  char our[50];
  char original[50];
  int d = 2147483;
  s21_sprintf(our, "Count: % d", d);
  sprintf(original, "Count: % d", d);
  ck_assert_str_eq(our, original);
}
END_TEST

START_TEST(D_minus) {
  char our[100];
  char original[100];
  s21_sprintf(our, "%-d", 0);
  sprintf(original, "%-d", 0);
  ck_assert_str_eq(our, original);
}
END_TEST

START_TEST(LD_1) {
  char our[200];
  char original[200];
  s21_sprintf(our, "%ld", 100000000000000000);
  sprintf(original, "%ld", 100000000000000000);
  ck_assert_str_eq(our, original);
}
END_TEST

START_TEST(d_plus) {
  char our[100];
  char original[100];
  s21_sprintf(our, "%+d", 0);
  sprintf(original, "%+d", 0);
  ck_assert_str_eq(our, original);
}
END_TEST

START_TEST(HD_1) {
  char our[100];
  char original[100];
  short int x = 400;
  s21_sprintf(our, "%hd", x);
  sprintf(original, "%hd", x);
  ck_assert_str_eq(our, original);
}
END_TEST

START_TEST(sprintf_D_2) {
  char our[100];
  char original[100];
  s21_sprintf(our, "|%d|", -555);
  sprintf(original, "|%d|", -555);
  ck_assert_str_eq(our, original);
}

START_TEST(sprintf_D_3) {
  char our[100];
  char original[100];
  s21_sprintf(our, "|%-20.18d|\n", -555);
  sprintf(original, "|%-20.18d|\n", -555);
  ck_assert_str_eq(our, original);
}
END_TEST

START_TEST(sprintf_D_4) {
  char our[100];
  char original[100];
  s21_sprintf(our, "|%20.2d|\n", -555);
  sprintf(original, "|%20.2d|\n", -555);
  ck_assert_str_eq(our, original);
}
END_TEST

START_TEST(sprintf_D_6) {
  char our[100];
  char original[100];
  s21_sprintf(our, "|%.10d|\n", 555);
  sprintf(original, "|%.10d|\n", 555);
  ck_assert_str_eq(our, original);
}
END_TEST

START_TEST(sprintf_D_7) {
  char our[100];
  char original[100];
  s21_sprintf(our, "|%.010d|\n", 555);
  sprintf(original, "|%.010d|\n", 555);
  ck_assert_str_eq(our, original);
}
END_TEST

START_TEST(test_D_12) {
  char result[20];
  char assert[20];
  s21_sprintf(result, "Count: %1.1d", 69);
  sprintf(assert, "Count: %1.1d", 69);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(sprintf_D_8) {
  char our[100];
  char original[100];
  s21_sprintf(our, "|%10d|\n", 555);
  sprintf(original, "|%10d|\n", 555);
  ck_assert_str_eq(our, original);
}
END_TEST

START_TEST(sprintf_D_9) {
  char our[100];
  char original[100];
  s21_sprintf(our, "|%-10d|\n", 555);
  sprintf(original, "|%-10d|\n", 555);
  ck_assert_str_eq(our, original);
}
END_TEST

START_TEST(sprintf_D_10) {
  char our[100];
  char original[100];
  s21_sprintf(our, "|%-10d|\n", -555);
  sprintf(original, "|%-10d|\n", -555);
  ck_assert_str_eq(our, original);
}
END_TEST

START_TEST(sprintf_D_11) {
  char our[100];
  char original[100];
  s21_sprintf(our, "|%-+10d|\n", -555);
  sprintf(original, "|%-+10d|\n", -555);
  ck_assert_str_eq(our, original);
}
END_TEST
START_TEST(sprintf_D_12) {
  char our[100];
  char original[100];
  s21_sprintf(our, "|%-+10d|\n", 555);
  sprintf(original, "|%-+10d|\n", 555);
  ck_assert_str_eq(our, original);
}
END_TEST
START_TEST(sprintf_D_13) {
  char our[100];
  char original[100];
  s21_sprintf(our, "|%- 10d|\n", 555);
  sprintf(original, "|%- 10d|\n", 555);
  ck_assert_str_eq(our, original);
}
END_TEST

START_TEST(sprintf_S_1) {
  char our[1024] = "\0";
  char original[1024] = "\0";
  s21_sprintf(our, "|%10s|", "abc");
  sprintf(original, "|%10s|", "abc");
  ck_assert_str_eq(our, original);
}
END_TEST

START_TEST(minus_S_1) {
  char our[1024] = "\0";
  char original[1024] = "\0";
  s21_sprintf(our, "|%-10s|", "abc");
  sprintf(original, "|%-10s|", "abc");
  ck_assert_str_eq(our, original);
}
END_TEST

START_TEST(sprintf_S_2) {
  char our[1024] = "\0";
  char original[1024] = "\0";
  s21_sprintf(our, "|%10s|", "abc abc");
  sprintf(original, "|%10s|", "abc abc");
  ck_assert_str_eq(our, original);
}
END_TEST

START_TEST(minus_S_2) {
  char our[1024] = "\0";
  char original[1024] = "\0";
  s21_sprintf(our, "|%-10s|", "abc abc");
  sprintf(original, "|%-10s|", "abc abc");
  ck_assert_str_eq(our, original);
}
END_TEST

START_TEST(accuracy_S_1) {
  char our[1024] = "\0";
  char original[1024] = "\0";
  s21_sprintf(our, "|%.3s|", "abc");
  sprintf(original, "|%.3s|", "abc");
  ck_assert_str_eq(our, original);
}
END_TEST

START_TEST(accuracy_S_2) {
  char our[1024] = "\0";
  char original[1024] = "\0";
  s21_sprintf(our, "|%.05s|", "abc");
  sprintf(original, "|%.05s|", "abc");
  ck_assert_str_eq(our, original);
}
END_TEST

START_TEST(accuracy_S_3) {
  char data[1024] = "\0";
  char data1[1024] = "\0";
  int our = s21_sprintf(data, "|%.010s|\n", "hello");
  int original = sprintf(data1, "|%.010s|\n", "hello");
  ck_assert_int_eq(our, original);
}
END_TEST

START_TEST(accuracy_S_4) {
  char data[1024] = "\0";
  char data1[1024] = "\0";
  int our = s21_sprintf(data, "|%.10s|\n", "hello");
  int original = sprintf(data1, "|%.10s|\n", "hello");
  ck_assert_int_eq(our, original);
}
END_TEST

START_TEST(accuracy_S_5) {
  char data[1024] = "\0";
  char data1[1024] = "\0";
  int our = s21_sprintf(data, "|%.3s| abc abc |%20s|\n", "HeLLo", "hello");
  int original = sprintf(data1, "|%.3s| abc abc |%20s|\n", "HeLLo", "hello");
  ck_assert_int_eq(our, original);
}
END_TEST

START_TEST(test_s_1) {
  char str1[1024] = "\0";
  char str2[1024] = "\0";

  char *format = "%s";
  char *val = "21R DSADA SDHASDOAMDSA sdas8d7nasd 111";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_char_multy) {
  char c = 'B';
  char result[1024] = "\0";
  char assert[1024] = "\0";
  s21_sprintf(result, "Char: %c%c%c", c, c, c);
  sprintf(assert, "Char: %c%c%c", c, c, c);
  ck_assert_str_eq(result, assert);
}
END_TEST

START_TEST(test_c_1) {
  char data[1024] = "\0";
  char data1[1024] = "\0";
  int our = s21_sprintf(data, "%c", '1');
  int original = sprintf(data1, "%c", '1');
  ck_assert_int_eq(our, original);
}
END_TEST

START_TEST(test_c_2) {
  char data[100];
  char data1[100];
  int our = s21_sprintf(data, "%c", 'A');
  int original = sprintf(data1, "%c", 'A');
  ck_assert_int_eq(our, original);
}
END_TEST

START_TEST(test_c_3) {
  char data[100];
  char data1[100];
  int our = s21_sprintf(data, "%c", '.');
  int original = sprintf(data1, "%c", '.');
  ck_assert_int_eq(our, original);
}
END_TEST

START_TEST(test_c_4) {
  char our[20] = {'\0'};
  char original[20] = {'\0'};
  char c = 'z';
  s21_sprintf(our, "%lc", c);
  sprintf(original, "%lc", c);
  ck_assert_str_eq(our, original);
}
END_TEST

START_TEST(test_c_5) {
  char our[20];
  char original[20];
  char c = 'a';
  s21_sprintf(our, "%-3c", c);
  sprintf(original, "%-3c", c);
  ck_assert_str_eq(our, original);
}
END_TEST

// START_TEST(test_i_0) {
//   char result[40];
//   char assert[40];
//   short int i = 32770;
//   s21_sprintf(result, "Count: %hi end", i);
//   sprintf(assert, "Count: %hi end", i);
//   ck_assert_str_eq(result, assert);
// }
// END_TEST

START_TEST(test_i_1) {
  char data[100];
  char data1[100];
  int our = s21_sprintf(data, "%i", 'a');
  int original = sprintf(data1, "%i", 'a');
  ck_assert_int_eq(our, original);
}
END_TEST

START_TEST(test_i_2) {
  char data[100];
  char data1[100];
  int our = s21_sprintf(data, "%i", 1);
  int original = sprintf(data1, "%i", 1);
  ck_assert_int_eq(our, original);
}
END_TEST

START_TEST(test_i_3) {
  char data[100];
  char data1[100];
  int our = s21_sprintf(data, "%i", 2147483647);
  int original = sprintf(data1, "%i", 2147483647);
  ck_assert_int_eq(our, original);
}
END_TEST

START_TEST(test_i_4) {
  char our[40];
  char original[40];
  int i = 327710;
  s21_sprintf(our, "%-+10.5i abc abc", i);
  sprintf(original, "%-+10.5i abc abc", i);
  ck_assert_str_eq(our, original);
}
END_TEST

START_TEST(test_i_5) {
  char our[40];
  char original[40];
  int i = 327710;
  s21_sprintf(our, "%+10.5i end", i + 1);
  sprintf(original, "%+10.5i end", i + 1);
  ck_assert_str_eq(our, original);
}
END_TEST

START_TEST(test_scdi_1) {
  char data[100], data1[100];
  int our = s21_sprintf(data, "%s%c%+5.5d% 5.i", "Hello world", 'a', 5, 5);
  int original = sprintf(data1, "%s%c%+5.5d% 5.i", "Hello world", 'a', 5, 5);
  ck_assert_int_eq(our, original);
}
END_TEST

START_TEST(LD_2) {
  char our[100];
  char original[100];
  s21_sprintf(our, "%2.5ld", -100000000000);
  sprintf(original, "%2.5ld", -100000000000);
  ck_assert_str_eq(our, original);
}
END_TEST

START_TEST(flag_u_1) {
  char our[100];
  char original[100];
  s21_sprintf(our, "%u", 0);
  sprintf(original, "%u", 0);
  ck_assert_str_eq(our, original);
}
END_TEST

START_TEST(flag_u_2) {
  char our[100];
  char original[100];
  s21_sprintf(our, "%.u", 0);
  sprintf(original, "%.u", 0);
  ck_assert_str_eq(our, original);
}
END_TEST

START_TEST(flag_u_3) {
  char our[100];
  char original[100];
  s21_sprintf(our, "%10.u", 0);
  sprintf(original, "%10.u", 0);
  ck_assert_str_eq(our, original);
}
END_TEST

START_TEST(flag_u_4) {
  char our[100];
  char original[100];
  s21_sprintf(our, "%10.2u", 0);
  sprintf(original, "%10.2u", 0);
  ck_assert_str_eq(our, original);
}
END_TEST

START_TEST(flag_u_5) {
  char our[100];
  char original[100];
  s21_sprintf(our, "%-10.2u", 0);
  sprintf(original, "%-10.2u", 0);
  ck_assert_str_eq(our, original);
}
END_TEST

START_TEST(flag_u_6) {
  char our[100];
  char original[100];
  s21_sprintf(our, "%-.2u", 0);
  sprintf(original, "%-.2u", 0);
  ck_assert_str_eq(our, original);
}
END_TEST

START_TEST(flag_u_7) {
  char our[200];
  char original[200];
  s21_sprintf(our, "%lu", 100000000000);
  sprintf(original, "%lu", 100000000000);
  ck_assert_str_eq(our, original);
}
END_TEST

START_TEST(flag_u_8) {
  char our[100];
  char original[100];
  short int x = 400;
  s21_sprintf(our, "%hu", x);
  sprintf(original, "%hu", x);
  ck_assert_str_eq(our, original);
}
END_TEST

START_TEST(flag_u_9) {
  char our[100];
  char original[100];
  s21_sprintf(our, "%-5u", 0);
  sprintf(original, "%-5u", 0);
  ck_assert_str_eq(our, original);
}
END_TEST

START_TEST(flag_u_10) {
  char our[100];
  char original[100];
  s21_sprintf(our, "%5u", 0);
  sprintf(original, "%5u", 0);
  ck_assert_str_eq(our, original);
}
END_TEST

START_TEST(flag_u_11) {
  char our[100];
  char original[100];
  s21_sprintf(our, "%-u", 0);
  sprintf(original, "%-u", 0);
  ck_assert_str_eq(our, original);
}
END_TEST

START_TEST(flag_u_12) {
  char our[100];
  char original[100];
  s21_sprintf(our, "%3.5u", 20);
  sprintf(original, "%3.5u", 20);
  ck_assert_str_eq(our, original);
}
END_TEST

START_TEST(flag_u_13) {
  char our[100];
  char original[100];
  s21_sprintf(our, "%3.5lu", 100000000000);
  sprintf(original, "%3.5lu", 100000000000);
  ck_assert_str_eq(our, original);
}
END_TEST

START_TEST(flag_u_14) {
  char our[100];
  char original[100];
  s21_sprintf(our, "%u", -1);
  sprintf(original, "%u", -1);
  ck_assert_str_eq(our, original);
}
END_TEST

START_TEST(flag_u_15) {
  char our[100];
  char original[100];
  s21_sprintf(our, "%.u", -1);
  sprintf(original, "%.u", -1);
  ck_assert_str_eq(our, original);
}
END_TEST

START_TEST(flag_u_16) {
  char our[100];
  char original[100];
  s21_sprintf(our, "%10.u", -1);
  sprintf(original, "%10.u", -1);
  ck_assert_str_eq(our, original);
}
END_TEST

START_TEST(flag_u_17) {
  char our[100];
  char original[100];
  s21_sprintf(our, "%10.2u", -1);
  sprintf(original, "%10.2u", -1);
  ck_assert_str_eq(our, original);
}
END_TEST

START_TEST(flag_u_18) {
  char our[100];
  char original[100];
  s21_sprintf(our, "%-10.2u", -1);
  sprintf(original, "%-10.2u", -1);
  ck_assert_str_eq(our, original);
}
END_TEST

START_TEST(flag_u_19) {
  char our[100];
  char original[100];
  s21_sprintf(our, "%-.2u", -1);
  sprintf(original, "%-.2u", -1);
  ck_assert_str_eq(our, original);
}
END_TEST

START_TEST(flag_u_21) {
  char our[100];
  char original[100];
  short int x = -400;
  s21_sprintf(our, "%hu", x);
  sprintf(original, "%hu", x);
  ck_assert_str_eq(our, original);
}
END_TEST

START_TEST(test_f_1) {
  char our[40];
  char original[40];
  float f = -14.537;
  s21_sprintf(our, "%.6f end", f);
  sprintf(original, "%.6f end", f);
  ck_assert_str_eq(our, original);
}
END_TEST

START_TEST(test_f_2) {
  char our[40];
  char original[40];
  float f = 14.537;
  s21_sprintf(our, "%2.2f end", f);
  sprintf(original, "%2.2f end", f);
  ck_assert_str_eq(our, original);
}
END_TEST

START_TEST(test_f_3) {
  char our[40];
  char original[40];
  float f = 1.0010021;
  s21_sprintf(our, "%f end", f);
  sprintf(original, "%f end", f);
  ck_assert_str_eq(our, original);
}
END_TEST

START_TEST(test_f_4) {
  char our[40];
  char original[40];
  float f = 0;
  s21_sprintf(our, "%f end", f);
  sprintf(original, "%f end", f);
  ck_assert_str_eq(our, original);
}
END_TEST

START_TEST(test_f_5) {
  char our[40];
  char original[40];
  float f = 0.;
  s21_sprintf(our, "%f end", f);
  sprintf(original, "%f end", f);
  ck_assert_str_eq(our, original);
}
END_TEST

START_TEST(test_f_6) {
  char our[40];
  char original[40];
  float f = -123.321;
  s21_sprintf(our, "%f end", f);
  sprintf(original, "%f end", f);
  ck_assert_str_eq(our, original);
}
END_TEST

START_TEST(test_f_7) {
  char our[40];
  char original[40];
  float f = -.0000001;
  s21_sprintf(our, "%f end", f);
  sprintf(original, "%f end", f);
  ck_assert_str_eq(our, original);
}
END_TEST

START_TEST(test_f_8) {
  char our[40];
  char original[40];
  float f = -.0000001;
  s21_sprintf(our, "%10f end", f);
  sprintf(original, "%10f end", f);
  ck_assert_str_eq(our, original);
}
END_TEST

START_TEST(test_f_9) {
  char our[40];
  char original[40];
  double f = -.0000001;
  s21_sprintf(our, "%3.5lf end", f);
  sprintf(original, "%3.5lf end", f);
  ck_assert_str_eq(our, original);
}
END_TEST

START_TEST(test_f_10) {
  char our[40];
  char original[40];
  double f = 3.2;
  s21_sprintf(our, "%+-3.5lf end", f);
  sprintf(original, "%+-3.5lf end", f);
  ck_assert_str_eq(our, original);
}
START_TEST(test_f_11) {
  char our[40];
  char original[40];
  double f = 3.2;
  s21_sprintf(our, "%- 3.5lf end", f);
  sprintf(original, "%- 3.5lf end", f);
  ck_assert_str_eq(our, original);
}
START_TEST(test_f_12) {
  char our[40];
  char original[40];
  double f = -3.2;
  s21_sprintf(our, "%- 3.5lf end", f);
  sprintf(original, "%- 3.5lf end", f);
  ck_assert_str_eq(our, original);
}
START_TEST(test_f_13) {
  char our[40];
  char original[40];
  double f = -3.2;
  s21_sprintf(our, "%- 3.lf end", f);
  sprintf(original, "%- 3.lf end", f);
  ck_assert_str_eq(our, original);
}
START_TEST(test_f_14) {
  char our[40];
  char original[40];
  double f = -3.45;
  s21_sprintf(our, "%- 3.lf end", f);
  sprintf(original, "%- 3.lf end", f);
  ck_assert_str_eq(our, original);
}
START_TEST(test_f_15) {
  char our[40];
  char original[40];
  double f = -3.45;
  s21_sprintf(our, "%3.lf end", f);
  sprintf(original, "%3.lf end", f);
  ck_assert_str_eq(our, original);
}
START_TEST(test_f_16) {
  char our[40];
  char original[40];
  double f = -3.45;
  s21_sprintf(our, "%3.1lf end", f);
  sprintf(original, "%3.1lf end", f);
  ck_assert_str_eq(our, original);
}
START_TEST(test_f_17) {
  char our[40];
  char original[40];
  double f = -0.45;
  s21_sprintf(our, "%.1lf end", f);
  sprintf(original, "%.1lf end", f);
  ck_assert_str_eq(our, original);
}
START_TEST(test_f_18) {
  char our[40];
  char original[40];
  double f = -0.45;
  s21_sprintf(our, "%.lf end", f);
  sprintf(original, "%.lf end", f);
  ck_assert_str_eq(our, original);
}
START_TEST(test_several_1) {
  char our[40];
  char original[40];
  double f = -0.45;
  s21_sprintf(our, "%.lf%10.u end", f, -1);
  sprintf(original, "%.lf%10.u end", f, -1);
  ck_assert_str_eq(our, original);
}
END_TEST
Suite *suite_s21_sprintf(void) {
  Suite *s38;
  TCase *tc38;
  s38 = suite_create("s21_sprintf");
  tc38 = tcase_create("case_sprintf");
  tcase_add_test(tc38, sprintf_D_0);
  tcase_add_test(tc38, sprintf_D_1);
  tcase_add_test(tc38, sprintf_D_2);
  tcase_add_test(tc38, sprintf_D_3);
  tcase_add_test(tc38, sprintf_D_4);
  tcase_add_test(tc38, sprintf_D_6);
  tcase_add_test(tc38, HD_1);
  tcase_add_test(tc38, d_plus);
  tcase_add_test(tc38, D_minus);
  tcase_add_test(tc38, sprintf_D_7);
  tcase_add_test(tc38, sprintf_D_8);
  tcase_add_test(tc38, sprintf_D_9);
  tcase_add_test(tc38, sprintf_D_10);
  tcase_add_test(tc38, sprintf_D_11);
  tcase_add_test(tc38, sprintf_D_12);
  tcase_add_test(tc38, sprintf_D_13);
  tcase_add_test(tc38, test_D_12);
  tcase_add_test(tc38, sprintf_S_1);
  tcase_add_test(tc38, minus_S_1);
  tcase_add_test(tc38, sprintf_S_2);
  tcase_add_test(tc38, test_s_1);
  tcase_add_test(tc38, minus_S_2);
  tcase_add_test(tc38, accuracy_S_1);
  tcase_add_test(tc38, accuracy_S_2);
  tcase_add_test(tc38, accuracy_S_3);
  tcase_add_test(tc38, accuracy_S_4);
  tcase_add_test(tc38, accuracy_S_5);
  tcase_add_test(tc38, test_c_1);
  tcase_add_test(tc38, test_c_2);
  tcase_add_test(tc38, test_c_3);
  tcase_add_test(tc38, test_c_4);
  tcase_add_test(tc38, test_c_5);
  tcase_add_test(tc38, test_char_multy);
  // tcase_add_test(tc38, test_i_0);
  tcase_add_test(tc38, test_i_1);
  tcase_add_test(tc38, test_i_2);
  tcase_add_test(tc38, test_i_3);
  tcase_add_test(tc38, test_i_4);
  tcase_add_test(tc38, test_i_5);
  tcase_add_test(tc38, LD_1);
  tcase_add_test(tc38, LD_2);
  tcase_add_test(tc38, HD_1);
  tcase_add_test(tc38, test_scdi_1);
  tcase_add_test(tc38, flag_u_1);
  tcase_add_test(tc38, flag_u_2);
  tcase_add_test(tc38, flag_u_3);
  tcase_add_test(tc38, flag_u_4);
  tcase_add_test(tc38, flag_u_5);
  tcase_add_test(tc38, flag_u_6);
  tcase_add_test(tc38, flag_u_7);
  tcase_add_test(tc38, flag_u_8);
  tcase_add_test(tc38, flag_u_9);
  tcase_add_test(tc38, flag_u_10);
  tcase_add_test(tc38, flag_u_11);
  tcase_add_test(tc38, flag_u_12);
  tcase_add_test(tc38, flag_u_13);
  tcase_add_test(tc38, flag_u_14);
  tcase_add_test(tc38, flag_u_15);
  tcase_add_test(tc38, flag_u_16);
  tcase_add_test(tc38, flag_u_17);
  tcase_add_test(tc38, flag_u_18);
  tcase_add_test(tc38, flag_u_19);
  tcase_add_test(tc38, flag_u_21);
  tcase_add_test(tc38, test_f_1);
  tcase_add_test(tc38, test_f_2);
  tcase_add_test(tc38, test_f_3);
  tcase_add_test(tc38, test_f_4);
  tcase_add_test(tc38, test_f_5);
  tcase_add_test(tc38, test_f_6);
  tcase_add_test(tc38, test_f_7);
  tcase_add_test(tc38, test_f_8);
  tcase_add_test(tc38, test_f_9);
  tcase_add_test(tc38, test_f_10);
  tcase_add_test(tc38, test_f_11);
  tcase_add_test(tc38, test_f_12);
  tcase_add_test(tc38, test_f_13);
  tcase_add_test(tc38, test_f_14);
  tcase_add_test(tc38, test_f_15);
  tcase_add_test(tc38, test_f_16);
  tcase_add_test(tc38, test_f_17);
  tcase_add_test(tc38, test_f_18);
  tcase_add_test(tc38, D_11);
  tcase_add_test(tc38, test_no_args);
  tcase_add_test(tc38, test_several_1);
  suite_add_tcase(s38, tc38);
  return s38;
}
