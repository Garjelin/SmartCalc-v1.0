#ifndef MATRIX_SUITECASES_H_
#define MATRIX_SUITECASES_H_

#include "../BACKEND/s21_calc.h"
#include <check.h>

Suite *suite_parser(void);

void run_tests(void);
void run_testcase(Suite *testcase);

#endif
