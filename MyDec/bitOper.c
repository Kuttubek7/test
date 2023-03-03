#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// принтует с десятичного в двоичный формат точность до 8 знаков
void print_bit_byte(unsigned char aByte) {
  printf("%c", (0b10000000 & aByte) ? '1' : '0');
  printf("%c", (0b01000000 & aByte) ? '1' : '0');
  printf("%c", (0b00100000 & aByte) ? '1' : '0');
  printf("%c", (0b00010000 & aByte) ? '1' : '0');
  printf("%c", (0b00001000 & aByte) ? '1' : '0');
  printf("%c", (0b00000100 & aByte) ? '1' : '0');
  printf("%c", (0b00000010 & aByte) ? '1' : '0');
  printf("%c", (0b00000001 & aByte) ? '1' : '0');
  printf("\n");
}

// тоже самое но точность до 32 знаков
// но с помощью цикла и маски
void print_bit(unsigned int aBute) {
  unsigned int mask = 1;
  for (size_t i = 31; i >= 1; --i) {
    printf("%c", (mask << i & aBute) ? '1' : '0');
    if (i == 1) printf("%c", (mask & aBute) ? '1' : '0');
  }
  printf("\n");
}

unsigned set_bit(unsigned aValue, unsigned aNumber) {
  // printf("%d", aValue | (1 << aNumber));
  return aValue | (1 << aNumber);
}

unsigned clear_bit(unsigned aValue, unsigned aNumber) {
  return aValue & (~(1 << aNumber));
}

// 282    7
unsigned invert_bit(unsigned aValue, unsigned aNumber) {
  // printf("%i", aValue ^ (1 << aNumber));
  return aValue ^ (1 << aNumber);
}

// 282      7
unsigned test_bit(unsigned aValue, unsigned aNumber) {
  printf("%i", aValue & (1 << aNumber));
  return aValue & (1 << aNumber);
}

unsigned n_of_s_bits(unsigned aValue) {
  unsigned res = 0;
  while (aValue) {
    aValue = aValue & (aValue - 1);
    res++;
  }
  return res;
}

void swap_xor(int *a, int *b) {
  *a = *a ^ *b;
  *b = *b ^ *a;
  *a = *a ^ *b;
  printf("aa%daa\n", a);
  printf("bb%dbb\n", b);
}

int main() {
  int ufc = 282;  // 10111
  int mma = 4;    // 01001
  test_bit(ufc, mma);
  return 0;
}
