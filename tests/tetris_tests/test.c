#include "test.h"


int main() {
  Suite *suite_array[] = {
      GetRenameSuite(),GetFsmSuite(), GetGameStateSuite(), GetPlayerSuite(), GetBoardSuite(),
      GetCollisionSuite()
  };

  int size = sizeof(suite_array) / sizeof(suite_array[0]);

  SRunner *sr;
  sr = srunner_create(suite_array[0]);

  for (int i = 1; i < size; ++i) {
    srunner_add_suite(sr, suite_array[i]);
  }

  srunner_set_fork_status(sr, CK_FORK);
  srunner_run_all(sr, CK_NORMAL);
  srunner_free(sr);

}
