#include <stdio.h>

unsigned int addBinary(unsigned int a, unsigned int b) {
    unsigned int carry = 0, sum = 0;

    for (int i = 0; i < sizeof(unsigned int) * 8; i++) {
        unsigned int bit_a = (a >> i) & 1;
        unsigned int bit_b = (b >> i) & 1;
        unsigned int bit_sum = bit_a ^ bit_b ^ carry;
        sum |= bit_sum << i;
        carry = (bit_a & bit_b) | (bit_a & carry) | (bit_b & carry);
    }

    return sum;
}

int main() {
    unsigned int a, b;

    printf("Enter two non-negative integers: ");
    scanf("%u %u", &a, &b);

    unsigned int sum = addBinary(a, b);

    printf("Binary sum: %u\n", sum);

    return 0;
}
