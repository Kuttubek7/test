#include <stdio.h>

struct res {
    int res[32];
    int ros;
    int hiz;
};


void decimal_to_binary(int decimal) {
    int binary[32];
    int i = 0;
    while (decimal > 0) {
        binary[i] = decimal % 2;
        decimal = decimal / 2;
        i++;
    }
    struct res result;
    
    for (int j = i - 1; j >= 0; j--) {
        result.res[j] = binary[j];
        printf("%d", result.res[j]);
        // printf("%d", binary[j]);
    }
    printf("\n");
}

int main() {
    struct res desult;
    int decimal = 34;
    decimal_to_binary(decimal);
    return 0;
}