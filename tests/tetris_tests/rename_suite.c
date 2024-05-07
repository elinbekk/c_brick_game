#include "test.h"

START_TEST(rename_suite_test_0) {
}

END_TEST

Suite *GetRenameSuite() {
  Suite *suite = suite_create("rename_suite");
  TCase *tc_case = tcase_create("rename_case");
  suite_add_tcase(suite, tc_case);
  tcase_add_test(tc_case, rename_suite_test_0);
  return suite;
}