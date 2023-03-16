#include <stdio.h>

int main() {
    unsigned int num, rotated_num;
    int num_bits, rotate_bits;

    printf("Enter a number: ");
    scanf("%u", &num);

    printf("Enter the number of bits to rotate: ");
    scanf("%d", &rotate_bits);

    num_bits = sizeof(num) * 8; // number of bits in an unsigned int

    rotated_num = (num << rotate_bits) | (num >> (num_bits - rotate_bits));

    printf("Rotated number: %u\n", rotated_num);

    return 0;
}
