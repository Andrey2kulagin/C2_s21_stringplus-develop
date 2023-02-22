#include "./test_main.h"

int main(void) {
  Suite *test_suites[] = {
      suite_s21_memchr(),   suite_s21_memcmp(),  suite_s21_memcpy(),
      suite_s21_memmove(),  suite_s21_memset(),  suite_s21_sprintf(),
      suite_s21_strcat(),   suite_s21_strncat(), suite_s21_strchr(),
      suite_s21_strcmp(),   suite_s21_strncmp(), suite_s21_strcpy(),
      suite_s21_strncpy(),  suite_s21_strcspn(), suite_s21_strpbrk(),
      suite_s21_strerror(), suite_s21_strlen(),  suite_s21_strrchr(),
      suite_s21_strspn(),   suite_s21_strstr(),  suite_s21_to_upper(),
      suite_s21_to_lower(), suite_s21_strtok(),  suite_s21_trim(),
      suite_s21_insert()};

  SRunner *suite_runner = srunner_create(test_suites[0]);
  srunner_set_fork_status(suite_runner, CK_NOFORK);

  for (s21_size_t i = 1; i < ARRAY_SIZE(test_suites); i++) {
    srunner_add_suite(suite_runner, test_suites[i]);
  }
  srunner_run_all(suite_runner, CK_NORMAL);
  int failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);

  if (failed_count != 0) {
    // Сигнализируем о том, что тестирование прошло неудачно.
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
