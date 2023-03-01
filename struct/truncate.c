#include <math.h>
#include <stdio.h>
#include <string.h>

// zsh: illegal hardware instruction ./a.out - что за ошибка?
// printf("%.2f", ((int)(100 * a)) / 100.0);
// https://stackoverflow.com/questions/12738892/how-to-truncate-a-floating-point-number-after-a-certain-number-of-decimal-places
// сколько цифр после точки

typedef struct {
  unsigned int bits[4];
} s21_decimal;

void truncate(char *mass) {
  //   int len = strlen(mass);
  printf("start: %s\n", mass);
  char symvol = 46;
  int kako = 0;
  int w = 0;

  int i = 0;
  for (i; i < strlen(mass); i++) {
    if (mass[i] == symvol) {
      kako = i + 1;
      mass[i] = 127;
    } else {
      i++;
    }
  }
  printf("naiden v index: %d\n", kako);
  w = i - kako;
  printf("skolko chifr posle tochki: %d\n", w);
  printf("the end: %s\n", mass);
}

int main() {
  float f = 58.416708;
  char mass[10] = {0};
  sprintf(mass, "%lf", f);
  truncate(mass);

  return 0;
}