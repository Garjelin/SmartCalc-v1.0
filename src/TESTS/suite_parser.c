#include "calc_suitecases.h"
#include "../BACKEND/s21_calc.h"

START_TEST(test1) {
  char* str = "8-7";
  int result = validate_string(str);
  ck_assert_int_eq(result, 0);
  double a = 1.0;
  double b = parser(str, 0.0);
  ck_assert_double_eq(a, b);
}
END_TEST

START_TEST(test2) {
  char* str = "-7";
  int result = validate_string(str);
  ck_assert_int_eq(result, 0);
  double a = -7.0;
  double b = parser(str, 0.0);
  ck_assert_double_eq(a, b);
}
END_TEST

START_TEST(test6) {
  char* str = "1*(1*(1*(1*(-1))))";
  int result = validate_string(str);
  ck_assert_int_eq(result, 0);
  int a = -1;
  int b = parser(str, 0.0);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(s21_test_0) {
  char* str = "5+5";
  int result = validate_string(str);
  ck_assert_int_eq(result, 0);
  double a = 10.0;
  double b = parser(str, 0.0);
  ck_assert_double_eq(a, b);
}
END_TEST

START_TEST(s21_test_1) {
  double a = 162.0;
  char* str = "4*5*2*2*2+2";
  int result = validate_string(str);
  ck_assert_int_eq(result, 0);
  double b = parser(str, 0.0);
  ck_assert_double_eq(b, a);
}
END_TEST

START_TEST(s21_test_2) {
  double a = 20;
  char* str = "150/10+5*2/2";
  int result = validate_string(str);
  ck_assert_int_eq(result, 0);
  double b = parser(str, 0.0);
  ck_assert_double_eq(b, a);
}
END_TEST

START_TEST(s21_test_3) {
  double a = 9.0;
  char* str = "5+5-2*3/6";
  int result = validate_string(str);
  ck_assert_int_eq(result, 0);
  double b = parser(str, 0.0);
  ck_assert_double_eq(b, a);
}
END_TEST

START_TEST(s21_test_4) {
  char* str = "123+0.456";
  int result = validate_string(str);
  ck_assert_int_eq(result, 0);
  double a = parser(str, 0.0);
  double b = 123.456;
  ck_assert_double_eq(a, b);
}

START_TEST(s21_test_5) {
  char* str = "-(-1)";
  int result = validate_string(str);
  ck_assert_int_eq(result, 0);
  double a = parser(str, 0.0);
  double b = 1;
  ck_assert_double_eq(a, b);
}

START_TEST(s21_test_6) {
  char* str = "cos(10mod2.2)";
  int result = validate_string(str);
  ck_assert_int_eq(result, 0);
  double a = parser(str, 0.0);
  ck_assert_double_eq(a, cos(fmod(10, 2.2)));
}

START_TEST(s21_test_7) {
  char* str = "sqrt(ln(10))";
  int result = validate_string(str);
  ck_assert_int_eq(result, 0);
  double a = parser(str, 0.0);
  ck_assert_double_eq(a, sqrt(log(10)));
}

START_TEST(s21_test_8) {
  char* str = "atan(10)+sin(10)";
  int result = validate_string(str);
  ck_assert_int_eq(result, 0);
  double a = parser(str, 0.0);
  ck_assert_double_eq_tol(a, atan(10) + sin(10), 1e-7);
}

START_TEST(s21_test_9) {
  char* str = "asin(1)";
  int result = validate_string(str);
  ck_assert_int_eq(result, 0);
  double a = parser(str, 0.0);
  ck_assert_double_eq(a, asin(1));
}

START_TEST(s21_test_10) {
  char* str = "10-20*(-10)";
  int result = validate_string(str);
  ck_assert_int_eq(result, 0);
  double a = parser(str, 0.0);
  double b = 210.0;
  ck_assert_double_eq(a, b);
}

START_TEST(s21_test_11) {
  char* str = "sin(8)";
  int result = validate_string(str);
  ck_assert_int_eq(result, 0);
  double a = sin(8);
  double b = parser(str, 0.0);
  ck_assert_int_eq(a, b);
}

END_TEST
START_TEST(s21_test_12) {
  char* str = "2+(5*5*5+5+2*2)/(2)";
  int result = validate_string(str);
  ck_assert_int_eq(result, 0);
  double a = parser(str, 0.0);
  double b = 69.0;
  ck_assert_double_eq(a, b);
}
END_TEST

START_TEST(s21_test_13) {
  char* str = "5mod2";
  int result = validate_string(str);
  ck_assert_int_eq(result, 0);
  double a = fmod(5, 2);
  double b = parser(str, 0.0);
  ck_assert_int_eq(a, b);
}

START_TEST(s21_test_14) {
  double b = 11.958851;
  char* str = "5+(3+sin(8/2-3.5))*2";
  int result = validate_string(str);
  ck_assert_int_eq(result, 0);
  double a = parser(str, 0.0);
  ck_assert_double_eq_tol(a, b, 1e-7);
}
END_TEST

START_TEST(s21_test_15) {
  char* str = "24*4-3*2";
  int result = validate_string(str);
  ck_assert_int_eq(result, 0);
  double b = 90.0;
  double a = parser(str, 0.0);
  ck_assert_double_eq(a, b);
}
END_TEST

START_TEST(s21_test_16) {
  double b = 4.0;
  char* str = "2-(-2)";
  int result = validate_string(str);
  ck_assert_int_eq(result, 0);
  double a = parser(str, 0.0);
  ck_assert_double_eq(a, b);
}
END_TEST

START_TEST(s21_test_17) {
  char* str = "-sin(9)";
  int result = validate_string(str);
  ck_assert_int_eq(result, 0);
  double a = parser(str, 0.0);
  ck_assert_double_eq(a, -sin(9));
}
END_TEST

START_TEST(s21_test_18) {
  char* str = "sin(9)-(-2)";
  int result = validate_string(str);
  ck_assert_int_eq(result, 0);
  double a = parser(str, 0.0);
  ck_assert_double_eq(a, sin(9) - (-2));
}
END_TEST

START_TEST(s21_test_19) {
  char* str = "-cos(9)";
  int result = validate_string(str);
  ck_assert_int_eq(result, 0);
  double a = parser(str, 0.0);
  ck_assert_double_eq(a, -cos(9));
}
END_TEST

START_TEST(s21_test_20) {
  char* str = "(-2)+2";
  double b = parser(str, 0.0);
  int result = validate_string(str);
  ck_assert_int_eq(result, 0);
  ck_assert_double_eq(b, 0.0);
}
END_TEST

START_TEST(s21_test_21) {
  char* str = "(-2.2)-2.2";
  double b = parser(str, 0.0);
  int result = validate_string(str);
  ck_assert_int_eq(result, 0);
  ck_assert_double_eq(b, -4.4);
}
END_TEST

START_TEST(s21_test_22) {
  char* str = "(-2.2)*(2.2)";
  double b = parser(str, 0.0);
  int result = validate_string(str);
  ck_assert_int_eq(result, 0);
  ck_assert_double_eq(b, (-2.2) * (2.2));
}
END_TEST

START_TEST(s21_test_23) {
  char* str = "(-2.2)/2.2";
  double b = parser(str, 0.0);
  int result = validate_string(str);
  ck_assert_int_eq(result, 0);
  ck_assert_float_eq(b, -1);
}
END_TEST

START_TEST(s21_test_24) {
  char* str = "(2.2)^(-2.2)";
  double b = parser(str, 0.0);
  int result = validate_string(str);
  ck_assert_int_eq(result, 0);
  ck_assert_double_eq_tol(b, 0.17647, 0.17647);
}
END_TEST

START_TEST(s21_test_25) {
  char* str = "sin(2)";
  double b = parser(str, 0.0);
  int result = validate_string(str);
  ck_assert_int_eq(result, 0);
  ck_assert_double_eq(b, sin(2));
}
END_TEST

START_TEST(s21_test_26) {
  char* str = "cos(2)";
  double b = parser(str, 0.0);
  int result = validate_string(str);
  ck_assert_int_eq(result, 0);
  ck_assert_double_eq_tol(b, cos(2), 1e-7);
}
END_TEST

START_TEST(s21_test_27) {
  char* str = "tan(2)";
  double b = parser(str, 0.0);
  int result = validate_string(str);
  ck_assert_int_eq(result, 0);
  ck_assert_ldouble_eq(b, tan(2));
}
END_TEST

START_TEST(s21_test_28) {
  char* str = "asin(1)";
  double b = parser(str, 0.0);
  int result = validate_string(str);
  ck_assert_int_eq(result, 0);
  ck_assert_ldouble_eq(b, asin(1));
}
END_TEST

START_TEST(s21_test_29) {
  char* str = "acos(1)";
  double b = parser(str, 0.0);
  int result = validate_string(str);
  ck_assert_int_eq(result, 0);
  ck_assert_ldouble_eq(b, acos(1));
}
END_TEST

START_TEST(s21_test_30) {
  char* str = "atan(1)";
  double b = parser(str, 0.0);
  int result = validate_string(str);
  ck_assert_int_eq(result, 0);
  ck_assert_ldouble_eq(b, atan(1));
}
END_TEST

START_TEST(s21_test_31) {
  char* str = "log(1)";
  double b = parser(str, 0.0);
  int result = validate_string(str);
  ck_assert_int_eq(result, 0);
  ck_assert_ldouble_eq(b, log(1));
}
END_TEST

START_TEST(s21_test_33) {
  char* str = "sqrt(1)";
  double b = parser(str, 0.0);
  int result = validate_string(str);
  ck_assert_int_eq(result, 0);
  ck_assert_ldouble_eq(b, sqrt(1));
}
END_TEST

START_TEST(s21_test_34) {
  char* str = "4mod8";
  double b = parser(str, 0.0);
  int result = validate_string(str);
  ck_assert_int_eq(result, 0);
  ck_assert_ldouble_eq(b, 4);
}
END_TEST

START_TEST(s21_test_35) {
  double b = 4.0;
  char* str = "x-(-x)";
  double a = parser(str, 2.0);
  int result = validate_string(str);
  ck_assert_int_eq(result, 0);
  ck_assert_double_eq(a, b);
}
END_TEST

START_TEST(s21_test_36) {
  char* str = "-sin(x)";
  double a = parser(str, 9.0);
  int result = validate_string(str);
  ck_assert_int_eq(result, 0);
  ck_assert_double_eq(a, -sin(9));
}
END_TEST
START_TEST(s21_test_37) {
  char* str = "sin(9)-(-x)";
  double a = parser(str, 2.0);
  int result = validate_string(str);
  ck_assert_int_eq(result, 0);
  ck_assert_double_eq(a, sin(9) - (-2));
}
END_TEST
START_TEST(s21_test_38) {
  char* str = "-cos(x)";
  int result = validate_string(str);
  ck_assert_int_eq(result, 0);
  double a = parser(str, 9.0);
  ck_assert_double_eq(a, -cos(9));
}
END_TEST
START_TEST(s21_test_39) {
  char* str = "(-x)+x";
  double a = parser(str, 2.0);
  int result = validate_string(str);
  ck_assert_int_eq(result, 0);
  ck_assert_double_eq(a, 0.0);
}
END_TEST

START_TEST(s21_test_40) {
  char* str = "(-x)-x";
  double a = parser(str, 2.2);
  int result = validate_string(str);
  ck_assert_int_eq(result, 0);
  ck_assert_double_eq(a, -4.4);
}
END_TEST

START_TEST(s21_test_41) {
  char* str = "(-x) * (x)";
  char dst[100];
  squeeze(str, dst);
  int result = validate_string(dst);
  ck_assert_int_eq(result, 0);
  double b = parser(dst, 2.2);
  double a = (-2.2) * (2.2);
  ck_assert_double_eq(b, a);
}
END_TEST

START_TEST(s21_test_42) {
  char* str = "(-x)/x";
  double b = parser(str, 2.2);
  int result = validate_string(str);
  ck_assert_int_eq(result, 0);
  ck_assert_float_eq(b, -1);
}
END_TEST

START_TEST(s21_test_43) {
  char* str = "(x)^(-x)";
  double b = parser(str, 2.2);
  int result = validate_string(str);
  ck_assert_int_eq(result, 0);
  ck_assert_double_eq_tol(b, 0.17647, 0.17647);
}
END_TEST

START_TEST(s21_test_44) {
  char* str = "sin(x)";
  double b = parser(str, 2.0);
  int result = validate_string(str);
  ck_assert_int_eq(result, 0);
  ck_assert_double_eq(b, sin(2));
}
END_TEST

START_TEST(s21_test_45) {
  char* str = "cos(x)";
  double b = parser(str, 0.0);
  int result = validate_string(str);
  ck_assert_int_eq(result, 0);
  ck_assert_double_eq_tol(b, cos(0), 1e-7);
}
END_TEST

START_TEST(s21_test_46) {
  char* str = "tan(x)";
  double b = parser(str, 2.0);
  int result = validate_string(str);
  ck_assert_int_eq(result, 0);
  ck_assert_ldouble_eq(b, tan(2));
}
END_TEST

START_TEST(s21_test_47) {
  char* str = "asin(x)";
  double b = parser(str, 1.0);
  int result = validate_string(str);
  ck_assert_int_eq(result, 0);
  ck_assert_ldouble_eq(b, asin(1));
}
END_TEST

START_TEST(s21_test_48) {
  char* str = "acos(x)";
  double b = parser(str, 1.0);
  int result = validate_string(str);
  ck_assert_int_eq(result, 0);
  ck_assert_ldouble_eq(b, acos(1));
}
END_TEST

START_TEST(s21_test_49) {
  char* str = "atan(x)";
  double b = parser(str, 1.0);
  int result = validate_string(str);
  ck_assert_int_eq(result, 0);
  ck_assert_ldouble_eq(b, atan(1));
}
END_TEST

START_TEST(s21_test_50) {
  char* str = "log(x)";
  double b = parser(str, 1.0);
  int result = validate_string(str);
  ck_assert_int_eq(result, 0);
  ck_assert_ldouble_eq(b, log(1));
}
END_TEST

START_TEST(s21_test_52) {
  char* str = "sqrt(x)";
  double b = parser(str, 1.0);
  int result = validate_string(str);
  ck_assert_int_eq(result, 0);
  ck_assert_ldouble_eq(b, sqrt(1));
}
END_TEST

START_TEST(s21_test_53) {
  char* str = "4modx";
  double b = parser(str, 1.0);
  int result = validate_string(str);
  ck_assert_int_eq(result, 0);
  ck_assert_ldouble_eq(b, 4%1);
}
END_TEST

START_TEST(s21_test_54) {
  char* str = "(-x)-x+";
  int result = validate_string(str);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(s21_test_55) {
  char* str = "lg(x)";
  int result = validate_string(str);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(s21_test_56) {
  char* str = "lo(x)";
  int result = validate_string(str);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(s21_test_57) {
  char* str = "sqt(1)";
  int result = validate_string(str);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(s21_test_58) {
  char* str = "sqr(1)";
  int result = validate_string(str);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(s21_test_59) {
  char* str = "acs(1)";
  int result = validate_string(str);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(s21_test_60) {
  char* str = "aco(1)";
  int result = validate_string(str);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(s21_test_61) {
  char* str = "asn(1)";
  int result = validate_string(str);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(s21_test_62) {
  char* str = "asi(1)";
  int result = validate_string(str);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(s21_test_63) {
  char* str = "atn(1)";
  int result = validate_string(str);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(s21_test_64) {
  char* str = "ata(1)";
  int result = validate_string(str);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(s21_test_65) {
  char* str = "cs(1)";
  int result = validate_string(str);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(s21_test_66) {
  char* str = "co(1)";
  int result = validate_string(str);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(s21_test_67) {
  char* str = "si(1)";
  int result = validate_string(str);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(s21_test_68) {
  char* str = "ta(1)";
  int result = validate_string(str);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(s21_test_69) {
  char* str = "od(1)";
  int result = validate_string(str);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(s21_test_70) {
  char* str = "md(1)";
  int result = validate_string(str);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(s21_test_71) {
  char* str = "mo(1)";
  int result = validate_string(str);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(s21_test_72) {
  char* string = "";
  int result = validate_string(string);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(s21_test_73) {
  char* str = "1/3";
  double b = parser(str, 1.0);
  int result = validate_string(str);
  ck_assert_int_eq(result, 0);
  ck_assert_ldouble_eq(b, 1.0/3.0);
}
END_TEST

START_TEST(s21_test_74) {
  char* str = "0.2*0.3";
  double b = parser(str, 1.0);
  int result = validate_string(str);
  ck_assert_int_eq(result, 0);
  ck_assert_ldouble_eq(b, 0.06);
}
END_TEST

START_TEST(s21_test_75) {
  char dst[1000];
  char* str = "0,2*0,3";
  int result = validate_string(str);
  change(str, dst, ',','.');
  str = dst;
  double b = parser(str, 1.0);
  ck_assert_int_eq(result, 0);
  ck_assert_ldouble_eq(b, 0.06);
}
END_TEST

Suite *suite_parser(void) {
  Suite *s = suite_create("create");
  TCase *tc = tcase_create("create");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, test1);
  tcase_add_test(tc, test2);
  tcase_add_test(tc, test6);
  tcase_add_test(tc, s21_test_0);
  tcase_add_test(tc, s21_test_1);
  tcase_add_test(tc, s21_test_2);
  tcase_add_test(tc, s21_test_3);
  tcase_add_test(tc, s21_test_4);
  tcase_add_test(tc, s21_test_5);
  tcase_add_test(tc, s21_test_6);
  tcase_add_test(tc, s21_test_7);
  tcase_add_test(tc, s21_test_8);
  tcase_add_test(tc, s21_test_9);
  tcase_add_test(tc, s21_test_10);
  tcase_add_test(tc, s21_test_11);
  tcase_add_test(tc, s21_test_12);
  tcase_add_test(tc, s21_test_13);
  tcase_add_test(tc, s21_test_14);
  tcase_add_test(tc, s21_test_15);
  tcase_add_test(tc, s21_test_16);
  tcase_add_test(tc, s21_test_17);
  tcase_add_test(tc, s21_test_18);
  tcase_add_test(tc, s21_test_19);
  tcase_add_test(tc, s21_test_20);
  tcase_add_test(tc, s21_test_21);
  tcase_add_test(tc, s21_test_22);
  tcase_add_test(tc, s21_test_23);
  tcase_add_test(tc, s21_test_24);
  tcase_add_test(tc, s21_test_25);
  tcase_add_test(tc, s21_test_26);
  tcase_add_test(tc, s21_test_27);
  tcase_add_test(tc, s21_test_28);
  tcase_add_test(tc, s21_test_29);
  tcase_add_test(tc, s21_test_30);
  tcase_add_test(tc, s21_test_31);
  tcase_add_test(tc, s21_test_33);
  tcase_add_test(tc, s21_test_34);
  tcase_add_test(tc, s21_test_35);
  tcase_add_test(tc, s21_test_36);
  tcase_add_test(tc, s21_test_37);
  tcase_add_test(tc, s21_test_38);
  tcase_add_test(tc, s21_test_39);
  tcase_add_test(tc, s21_test_40);
  tcase_add_test(tc, s21_test_41);
  tcase_add_test(tc, s21_test_42);
  tcase_add_test(tc, s21_test_43);
  tcase_add_test(tc, s21_test_44);
  tcase_add_test(tc, s21_test_45);
  tcase_add_test(tc, s21_test_46);
  tcase_add_test(tc, s21_test_47);
  tcase_add_test(tc, s21_test_48);
  tcase_add_test(tc, s21_test_49);
  tcase_add_test(tc, s21_test_50);
  tcase_add_test(tc, s21_test_52);
  tcase_add_test(tc, s21_test_53);
  tcase_add_test(tc, s21_test_54);
  tcase_add_test(tc, s21_test_55);
  tcase_add_test(tc, s21_test_56);
  tcase_add_test(tc, s21_test_57);
  tcase_add_test(tc, s21_test_58);
  tcase_add_test(tc, s21_test_59);
  tcase_add_test(tc, s21_test_60);
  tcase_add_test(tc, s21_test_61);
  tcase_add_test(tc, s21_test_62);
  tcase_add_test(tc, s21_test_63);
  tcase_add_test(tc, s21_test_64);
  tcase_add_test(tc, s21_test_65);
  tcase_add_test(tc, s21_test_66);
  tcase_add_test(tc, s21_test_67);
  tcase_add_test(tc, s21_test_68);
  tcase_add_test(tc, s21_test_69);
  tcase_add_test(tc, s21_test_70);
  tcase_add_test(tc, s21_test_71);
  tcase_add_test(tc, s21_test_72);
  tcase_add_test(tc, s21_test_73);
  tcase_add_test(tc, s21_test_74);
  tcase_add_test(tc, s21_test_75);
  return s;
}
