#include <stdio.h>

int main() {
    unsigned int num, reversed_num = 0;
    int bits = sizeof(num) * 8; // number of bits in an unsigned int

    printf("Enter a number: ");
    scanf("%u", &num);

    for (int i = 0; i < bits; i++) {
        reversed_num <<= 1; // left shift the reversed number by 1 bit
        reversed_num |= num & 1; // set the rightmost bit of reversed_num to the current bit of num
        num >>= 1; // right shift num by 1 bit
    }

    printf("Reversed number: %u\n", reversed_num);

    return 0;
}
