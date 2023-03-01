#include <math.h>
#include <stdio.h>
#include <string.h>

// shift+option+f выравнивает по стилю гугл на маке

typedef struct {
  long int bits[4];
} s21_decimal;

void decTOint(int low[], int scale) {
  int i = 12;  // 32
  int p = 0;
  int num = 0;
  while (i >= 0) {
    if (low[i] == 1) {
      num += pow(2, p);
      i--;
      p++;
    } else {
      i--;
      p++;
    }
  }
  // printf("\n++%d++\n", num); // num = 58
  float done = num;
  // printf("\n--%f--\n", done); // done = 5814.000000
  // printf("\n((%d))\n", scale); // scale = 2
  printf("\n");
  for (int j = 0; j < scale; j++) {
    done = done / 10;
    // printf("++%f++\n", done);
  }
  printf("\n==%f==\n", done);
}

void decimal_to_binary(
    unsigned int
        decimal) {  // Функция для перевода десятичного числа в двоичный код
  int binaryNum[32];  // Объявляем массив для хранения двоичных цифр
  int i = 0;
  while (decimal > 0) {
    binaryNum[i] = decimal % 2;
    decimal = decimal / 2;
    i++;
  }
  for (int j = i - 1; j >= 0; j--) {
    printf("%d", binaryNum[j]);  // Выводим двоичные цифры в обратном порядке
  }
  int sortirovka[32];
  int w = 0;
  for (int j = i - 1; j >= 0; j--) {
    sortirovka[w] = binaryNum[j];
    w++;
  }
  decTOint(sortirovka, 2);
}

void floatToDec(float num, s21_decimal dec) {
  printf("num: %.2f = ", num);
  dec.bits[2] = 0;
  for (size_t i = 0; i < 2; i++) {
    num *= 10;
    // dec.bits[2]++;
  }
  // printf("\n%d\n" , dec.bits[2]);
  // printf("num ===%f\n" , num);
  decimal_to_binary(num);
}

// int main(int argc, char const *argv[]) {
//     s21_decimal dec ;
//     float num = 58.14;
//     printf("num: %.2f = " , num);
//     floatToDec(num , dec);
//     return 0;
// }

int fintBit(s21_decimal bin, int n) {
  int mask = 1 << n;
  int res = bin.bits[0] & mask;

  return res >> n;
}

int main(int argc, char const *argv[]) {
  int a = 11;
  s21_decimal bin;
  char del[96];

  bin.bits[0] = 4294967297;  // 4 294 967 295
  printf("bits[0]: %d", bin.bits[0]);
  printf("\nbits[1]: %d", bin.bits[1]);
  // unsigned int = 4 байта или 32 бита
  return 0;
}
