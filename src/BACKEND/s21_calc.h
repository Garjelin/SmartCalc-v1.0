#ifndef MATRIX_H_
#define MATRIX_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


typedef struct stack {
  double number;
  int operation;
  int priority;
  struct stack *next;
} Stack;

typedef struct creditpay {
  double payment;
  double last_pay;
  double overpayment;
  double total;
} Creditpay;

void Push(Stack **head, double number, int operation, int priority);
void Pop(Stack **head);
double parser(char *str, double x);
double calculate_bin(double a, double b, int op);
double calculate_trig(double a, int op);
int priorityCalc(int i);
double evaluete(Stack **stackNum, Stack **stackOp, int i);
void push_and_pop(Stack **stackNum, Stack **stackOp, double *res, int op);
int validate_string(char* string);
void squeeze(char const *str, char *dst);
void change(char const *str, char *dst,char c1, char c2);

#endif
