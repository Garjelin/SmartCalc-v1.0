#include "s21_calc.h"

void squeeze(char const *str, char *dst) {
  int i = 0;
  int j = 0;
  while (str[i] != '\0') {
    if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n') {
      dst[j] = str[i];
      ++j;
    }
    ++i;
  }
  dst[j] = '\0';
}

void change(char const *str, char *dst, char c1, char c2) {
  int i = 0;
  while (str[i] != '\0') {
    if (str[i] == c1) {
      dst[i] = c2;
    } else
      dst[i] = str[i];
    ++i;
  }
  dst[i] = '\0';
}

int validate_string(char *str) {
  int bug = 0;

  if (strlen(str) == 0 || strchr(")*/^.", str[0]) ||
      strchr("(+-*/^", str[strlen(str) - 1])) {
    bug = 1;
  } else {
    int scob_check = 0;
    for (int i = 0; str[i] != '\0' && i >= 0; i++) {
      if (!strchr("1234567890()+-*/^mcstalx.,", str[i])) {
        i = -2;
      } else {
        if (strchr(".", str[i])) {
          if ((!strchr("1234567890", str[i - 1]) ||
               !strchr("1234567890", str[i + 1]) || !str[i + 1] ||
               !str[i - 1])) {
            i = -2;
          } else {
            int count = 0;
            for (int k = i + 1; strchr("1234567890.", str[k]); k++) {
              if (str[k] == '.') count++;
            }
            if (count > 0) i = -2;
          }
        }

        if (strchr("-+*/^", str[i]) &&
            (!strchr("1234567890(cstalx", str[i + 1]) || !str[i + 1])) {
          i = -2;
        }

        if (strchr("x", str[i]) && !strchr("+-*/^)", str[i + 1])) {
          i = -2;
        }

        if (strchr("m", str[i])) {
          if (str[i] == 'm' && str[i + 1] == 'o' && str[i + 2] == 'd') i += 2;
          if (!strchr("1234567890(x", str[i + 1]) || !str[i + 1] ||
              (!strchr("1234567890)x", str[i - 3]) || !str[i - 3]))
            i = -2;
        }

        if (strchr("cstal", str[i])) {
          if (str[i] == 's' && str[i + 1] == 'q' && str[i + 2] == 'r' &&
              str[i + 3] == 't')
            i += 3;
          if (str[i] == 'a' && str[i + 1] == 'c' && str[i + 2] == 'o' &&
              str[i + 3] == 's')
            i += 3;
          if (str[i] == 'a' && str[i + 1] == 's' && str[i + 2] == 'i' &&
              str[i + 3] == 'n')
            i += 3;
          if (str[i] == 'a' && str[i + 1] == 't' && str[i + 2] == 'a' &&
              str[i + 3] == 'n')
            i += 3;
          if (str[i] == 'c' && str[i + 1] == 'o' && str[i + 2] == 's') i += 2;
          if (str[i] == 's' && str[i + 1] == 'i' && str[i + 2] == 'n') i += 2;
          if (str[i] == 't' && str[i + 1] == 'a' && str[i + 2] == 'n') i += 2;
          if (str[i] == 'm' && str[i + 1] == 'o' && str[i + 2] == 'd') i += 2;
          if (str[i] == 'l' && str[i + 1] == 'o' && str[i + 2] == 'g') i += 2;
          if (str[i] == 'l' && str[i + 1] == 'n') i += 1;
          if (!strchr("1234567890(x", str[i + 1]) || !str[i + 1]) i = -2;
        }

        if (str[i] == '(') {
          if (str[i + 1] == ')' || strchr("^/*.", str[i + 1])) {
            i = -2;
          }
          scob_check++;
        }

        if (str[i] == ')') scob_check--;
      }

      if (i < 0) {
        bug = 1;
      }
    }

    if (scob_check != 0) bug = 1;
  }
  return bug;
}