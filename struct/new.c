#include <stdio.h>
#include <math.h>

typedef struct 
{
    int bits[4];
} s21_decimal;

int decTOint(int low[] ,  int scale) {
  int i = 31;
  int p = 0;
  int num = 0;
  while (i > 0) {
    if (low[i] == 1) num += pow(2, p);
    i--;
    p++;
  }
  printf("\nnum==%d\n", num);
float done = num;
  printf("donne\n%f\n", done);
  for (size_t i = 0; i < scale; i++)
  {
    done = done / 10;
  }


  
  printf("donne\n%f\n", done);
  printf("\n%d", num);


  return 0;
}

void decimal_to_binary(unsigned int decimal) { // Функция для перевода десятичного числа в двоичный код
    int binaryNum[32];// Объявляем массив для хранения двоичных цифр
    int i = 0;
    while (decimal > 0) {
        binaryNum[i] = decimal % 2;
        decimal = decimal / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binaryNum[j]); // Выводим двоичные цифры в обратном порядке
    }
    decTOint(binaryNum , 2);
}


void floatToDec(float num, s21_decimal dec)
{
    
     printf("num ===%f\n" , num);
    dec.bits[2] = 0;
    for (size_t i = 0; i < 2; i++)
    {
        num *=  10 ;
        dec.bits[2] ++;

    }

        printf("\n%d\n" , dec.bits[2]);
        printf("num ===%f\n" , num);
        decimal_to_binary(num);

    
}

int main(int argc, char const *argv[])
{
    s21_decimal dec ;
    floatToDec(58.14 , dec);

    return 0;
}
