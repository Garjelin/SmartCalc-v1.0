#include "calc_suitecases.h"
#include "../BACKEND/s21_calc.h"

int main(void) {
  Suite *cases[] = {suite_parser(), NULL};

  for (Suite **current_testcase = cases; *current_testcase != NULL;
       current_testcase++) {
    run_testcase(*current_testcase);
  }
  return 0;
}

void run_testcase(Suite *testcase) {
  SRunner *sr = srunner_create(testcase);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);
  srunner_free(sr);
}
