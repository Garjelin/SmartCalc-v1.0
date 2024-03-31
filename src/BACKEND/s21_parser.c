#include "s21_calc.h"

void Push(Stack **head, double number, int operation, int priority) {
  Stack *tmp = ((Stack *)calloc(255, sizeof(Stack)));
  tmp->number = number;
  tmp->operation = operation;
  tmp->priority = priority;
  tmp->next = *head;
  *head = tmp;
}

void Pop(Stack **head) {
  if (*head != NULL) {
    Stack *tmp = *head;
    *head = (*head)->next;
    free(tmp);
    tmp = NULL;
  }
}

double calculate_bin(double a, double b, int op) {
  long double result = 0;
  switch (op) {
    case 1:
      result = a + b;
      break;
    case 2:
      result = a - b;
      break;
    case 3:
      result = a * b;
      break;
    case 4:
      result = (long double)a / (long double)b;
      break;
    case 5:
      result = fmod(a, b);
      break;
    case 6:
      result = pow(a, b);
      break;
  }
  return result;
}

double calculate_trig(double a, int op) {
  double result = 0;
  switch (op) {
    case 7:
      result = cos(a);
      break;
    case 8:
      result = sin(a);
      break;
    case 9:
      result = tan(a);
      break;
    case 10:
      result = acos(a);
      break;
    case 11:
      result = asin(a);
      break;
    case 12:
      result = atan(a);
      break;
    case 13:
      result = sqrt(a);
      break;
    case 14:
      result = log(a);
      break;
    case 15:
      result = log10(a);
      break;
  }
  return result;
}

void push_and_pop(Stack **stackNum, Stack **stackOp, double *res, int op) {
  if (*stackNum != NULL && *stackOp != NULL) {
    if (op >= 1 && op < 7 && (*stackNum)->next != NULL) {
      *res = calculate_bin((*stackNum)->next->number, (*stackNum)->number,
                           (*stackOp)->operation);
      Pop(stackNum);
      Pop(stackNum);
      Pop(stackOp);
      Push(stackNum, *res, 0, 0);
    } else if (op >= 7 && op <= 15) {
      *res = calculate_trig((*stackNum)->number, (*stackOp)->operation);
      Pop(stackNum);
      Pop(stackOp);
      Push(stackNum, *res, 0, 0);
    }
  }
}

double evaluete(Stack **stackNum, Stack **stackOp,
                int i) {  // обработка приоритетов
  double res = 0;
  if ((*stackOp) == NULL) {
    Push(stackOp, 0, i, priorityCalc(i));
  } else if ((*stackOp)->priority < priorityCalc(i) ||
             (*stackOp)->operation == 6) {
    Push(stackOp, 0, i, priorityCalc(i));
  } else {
    if (((*stackOp)->operation < 7 && (*stackNum)->next != NULL) ||
        (*stackOp)->operation > 6) {
      while ((*stackOp) != NULL && (priorityCalc(i) <= (*stackOp)->priority)) {
        push_and_pop(stackNum, stackOp, &res, (*stackOp)->operation);
      }
    }
    Push(stackOp, 0, i, priorityCalc(i));
  }
  return res;
}

int priorityCalc(int i) {
  return ((i == 1 || i == 2)             ? 1
          : (i == 3 || i == 4 || i == 5) ? 2
          : (i == 6)                     ? 3
                                         : 4);
}

double parser(char *str, double x) {
  const char *operations[15] = {"+",    "-",    "*",    "/",   "mod",
                                "^",    "cos",  "sin",  "tan", "acos",
                                "asin", "atan", "sqrt", "ln",  "log"};
  double res = 0;
  Stack *stackNum = NULL;
  Stack *stackOp = NULL;
  int unary = 1;
  while (*str) {
    if (isdigit(*str)) {  // number
      double num = strtod(str, &str);
      Push(&stackNum, num, 0, 0);

      // if ((stackOp!= NULL && unary == 1) && (stackNum->next == NULL ||unary
      // == 1)) {
      //   if ((stackOp)->operation == 2){
      //     Push(&stackNum, 0, 0, 0);
      //     }
      // }
      res = stackNum->number;
      unary = 0;

    } else if (*str == '(') {
      Push(&stackOp, 0, 16, 0);
      str++;

      if (*str == '-' || *str == '+') {
        unary = 1;
      }
    } else if (*str == ')') {
      while (stackOp->operation != 16) {
        if (stackOp->operation <= 6) {
          res = calculate_bin((stackNum)->next->number, (stackNum)->number,
                              (stackOp)->operation);
          Pop(&stackNum);
          Pop(&stackNum);
          Pop(&stackOp);
          Push(&stackNum, res, 0, 0);
        } else {
          res = calculate_trig((stackNum)->number, (stackOp)->operation);
          Pop(&stackNum);
          Pop(&stackOp);
          Push(&stackNum, res, 0, 0);
        }
      }
      Pop(&stackOp);
      str++;
    } else if (*str == 'x') {
      Push(&stackNum, x, 0, 0);
      res = stackNum->number;
      str++;
      unary = 0;
    } else {
      for (int i = 0; i < 15; i++) {
        if (!strncmp(str, operations[i], strlen(operations[i]))) {
          if (unary && (i <= 1)) {
            Push(&stackNum, 0, 0, 0);
            unary = 0;
          }
          res = evaluete(&stackNum, &stackOp, i + 1);
          str += strlen(operations[i]);
          break;
        }
      }
    }

    // if(test) {
    // unary--;
    // test--;
    // }
  }

  while (stackOp) {
    push_and_pop(&stackNum, &stackOp, &res, stackOp->operation);
  }
  Pop(&stackNum);
  return res;
  // return 0;
}

// int parser(char* string) {
//   (void)string;
//   return 0;
// }
