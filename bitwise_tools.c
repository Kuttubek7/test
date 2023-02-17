#include "biblioteka.h"

// переводит с десятичного в двоичную систему
void print_bits_state(char aCh) {
  printf("%i: ", (unsigned char)aCh);
  printf("%i", (aCh & BIT_8) ? 1 : 0);
  printf("%i", (aCh & BIT_7) ? 1 : 0);
  printf("%i", (aCh & BIT_6) ? 1 : 0);
  printf("%i", (aCh & BIT_5) ? 1 : 0);
  printf("%i", (aCh & BIT_4) ? 1 : 0);
  printf("%i", (aCh & BIT_3) ? 1 : 0);
  printf("%i", (aCh & BIT_2) ? 1 : 0);
  printf("%i\n", (aCh & BIT_1) ? 1 : 0);
}