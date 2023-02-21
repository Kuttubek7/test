// #include "main.h"
#include <stdio.h>

// #define BIT_16 0x20480
// #define BIT_15 0x10240
// #define BIT_14 0x5120
// #define BIT_13 0x2560
// #define BIT_12 0x1280
// #define BIT_11 0x640
// #define BIT_10 0x320
// #define BIT_9 0x160
#define BIT_8 0x80
#define BIT_7 0x40
#define BIT_6 0x20
#define BIT_5 0x10
#define BIT_4 0x08
#define BIT_3 0x04
#define BIT_2 0x02
#define BIT_1 0x01

// переводит с десятичного в двоичную систему
// этот функция работает быстрее
void print_bits_state(unsigned int aCh) {
  printf("%i: ", aCh);
  // printf("%i", (aCh & BIT_16) ? 1 : 0);
  // printf("%i", (aCh & BIT_15) ? 1 : 0);
  // printf("%i", (aCh & BIT_14) ? 1 : 0);
  // printf("%i", (aCh & BIT_13) ? 1 : 0);
  // printf("%i", (aCh & BIT_12) ? 1 : 0);
  // printf("%i", (aCh & BIT_11) ? 1 : 0);
  // printf("%i", (aCh & BIT_10) ? 1 : 0);
  // printf("%i", (aCh & BIT_9) ? 1 : 0);
  printf("%i", (aCh & BIT_8) ? 1 : 0);
  printf("%i", (aCh & BIT_7) ? 1 : 0);
  printf("%i", (aCh & BIT_6) ? 1 : 0);
  printf("%i", (aCh & BIT_5) ? 1 : 0);
  printf("%i", (aCh & BIT_4) ? 1 : 0);
  printf("%i", (aCh & BIT_3) ? 1 : 0);
  printf("%i", (aCh & BIT_2) ? 1 : 0);
  printf("%i\n", (aCh & BIT_1) ? 1 : 0);
}

// переводит с десятичного в двоичную систему
void print_bits_state_shift(unsigned char aCh) {
  int i;
  printf("%i: ", aCh);
  for (i = 7; i >= 0; --i) {
    printf("%i", ((aCh >> i) & BIT_1) ? 1 : 0);
  }
  printf("\n");
}

unsigned char set_bit(unsigned char aCh, unsigned char aN) {
  // return (aCh | aN);
  return (aCh | (1 << (aN - 1)));
}
unsigned char clear_bit(unsigned char aCh, unsigned char aN) {
  return (aCh & ~(1 << (aN - 1)));
}
unsigned char invert_bit(unsigned char aCh, unsigned char aN) {
  return (aCh ^ (1 << (aN - 1)));
}

unsigned char test_bit(unsigned char aCh, unsigned char aN) {
  return (aCh & (1 << (aN - 1)));
}

int s21_add_int(unsigned char aCh, unsigned char aN, unsigned char res) {
  return res = aCh | aN;
}

// 1 2 3 A
// 4 5 6 B
// 7 8 9 C
// D 0 E F
// это шестнадцатиричное число

// на вход приходит четыре символа
// допустим 1234 [0001][0010][0011][0100] - в общей сложности это займет 2 байта
// или же 8 битов
// на выходe мы должны выдать какое-то значение в 4 байта. почему 4 байта?
// потому-что мы должны будем зашифровать всэ это в шестнадцатиричной системе

int main() {
  print_bits_state(255);
  return 0;
}

// 48 - 00110000
//  6 - 00000110
// |
// 54 - 00110110