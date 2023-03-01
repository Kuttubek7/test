#include <stdio.h>

// если у нас дается число например 58.14
// то при переводе в двоичную у нас должен получится 111010.001
// но правильно ли это? он должен ли 58.140000 вот эти вот 4 ноля тоже брать в счет? и вычислить
// 58.140000 = 111010.00100011110

void decimal_to_binary(unsigned char decimal) { // Функция для перевода десятичного числа в двоичный код
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
}

void float_to_binary(double decimal) {
    // printf("==%lf==", decimal);
    double binaryNum[32];
    int i = 0;
    while(decimal > 0) {
        binaryNum[i] = decimal * 2;
        // decimal = decimal * 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binaryNum[j]); // Выводим двоичные цифры в обратном порядке
    }
}

int main(void) {
    float num = 12.34;
    int intPart = (int)num; // Отделяем целую часть числа
    float fracPart = num - intPart; // Отделяем дробную часть числа

    printf("Целая часть в двоичном формате: ");
    decimal_to_binary(intPart);

    printf("\nДробная часть в двоичном формате: ");
    float_to_binary(fracPart);
    // for (int i = 0; i < 16; i++) { // Дробная часть кодируется в 4-8-16-32 битах
    //     fracPart *= 2;
    //     int bit = (int)fracPart;
    //     printf("%d", bit);
    //     fracPart -= bit;
    // }
    return 0;
}
// число 12.34
// 12 = 1100
// output: 1100
// 34 = 100010
// output: 0101
// 12.34 = 1100.01010111000