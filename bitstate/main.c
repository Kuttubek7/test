
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int bits[4];
} decimal;

#define BIT_1 0x01

// может возводить в степень до 30
int stepen(uint32_t n) {
  uint32_t x = 2;
  for (int i = 1; i < n;) {
    x = x * 2;
    i++;
  }
  printf("res stepen: %d\n", x);
  return x;
}

// сдвиг в право. первым аргументом получает цифру и вторым аргументом получает
// на сколько сдвинуть в право
int sdvig_pravo(uint32_t n, uint32_t y) {
  n = n << y;
  printf("%d\n", n);
  return n;
}

// ищем и находим старший бит
int naiti_starshiy_bit(uint32_t n) {
  int i = 0, x = 100;  //
  for (i; x > 0; i++) {
    x >>= 1;
  }
  printf("%i", (i - 1));
  return (i - 1);
}

// выясняем сколько единицек в нашем цифре (в представлении в двоичном формате)
int skolko_edinichek(unsigned int aValue) {
  unsigned res = 0;
  while (aValue) {
    aValue = aValue & (aValue - 1);
    res++;
  }
  printf("vot stolko: %d edinichek\n", res);
  return res;
}

// первым аргументом мы передаем какую цифру перевести в двочный код
// а вторым параметром сколько битов вывести на экран (макс. 32)
int int_to_bit(uint32_t n, uint32_t y) {
  char res[y];
  char res1[y];
  int j = 0;
  printf("itb %i: ", n);
  for (int i = (y - 1); i >= 0; i--) {
    res[i] = ((n >> i) & BIT_1) ? 1 : 0;
    res1[j] = res[i];
    printf("%i", res1[j]);
    j++;
  }
  printf("\n");
  // skolko_edinichek(res1, y);
  return *res1;
}

void IntToDec(char *str) {
  // printf("==%d==\n", value);
  printf("\n");
  for (int i = 0; i <= 30; i++) {
    printf("%i", str[i]);
  }
  printf("\n");
}

int slojenie(uint32_t value1, uint32_t value2, uint32_t result) {
  printf("%i & %i = ", value1, value2);
  char mass[100];
  int j = 0;
  for (int i = 30; i >= 0; i--) {
    mass[j] = (((value1 >> i) & (value2 >> i) & BIT_1) ? 1 : 0);
    printf("%i", mass[j]);
    j++;
  }
  printf("\n");
  IntToDec(mass);
  return 0;
}
int floatToDec(float value, decimal res) {
  int result = value / 32;
  if (result == 1) {
    res.bits[0] = value;
  } else if (result > 1) {
    res.bits[1] = value;
  } else if (result >= 2) {
    res.bits[2] = value;
  } else if (result >= 3) {
    res.bits[3] = value;
  }
  int mass[100] = {0};
  int mass1[100] = {0};
  int j = 0;
  printf("++%lf++: ", value);
  for (int i = 0; i < 32; i++) {
    value *= 2;
    int bit = (int)value;
    printf("%d", bit);
    value -= bit;
  }
  printf("\n");
  return 0;
}

// побитовый сдвиг влево умножает
// побитовый сдвиг вправо делит
// float - 4 байта
// double - 8 байт
// long long - 8 байт
// lond double - 8 байт

// binary to int
int main(void) {
  int a = 63;
  int b = 31;
  printf("%d %o %x %X\n", a, a, a, a);
  printf("%d %o %x %X\n", b, b, b, b);
  return 0;
}
