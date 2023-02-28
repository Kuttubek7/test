#include <stdio.h>
#include <stdint.h>

// typedef signed int uint64_t;

void print_binary(uint64_t n) {
    for (int i = 63; i >= 0; i--) {
    uint64_t mask = 1ull << i;
    printf("%c", (n & mask) ? '1' : '0');
    }
}

void double_to_binary(double x) {
    uint64_t *p = (uint64_t *) &x;
    uint64_t n = *p;
    printf("Binary representation of %lf: ", x);
    print_binary(n);
    printf("\n");
}

int main() {
    // double x = 3.14159;
    double x = 1.2;
    double_to_binary(x);
    return 0;
}
