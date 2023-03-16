#include <stdio.h>

int main() {
    unsigned int num;

    printf("Enter a number: ");
    scanf("%u", &num);

    unsigned int result = num & (num - 1);

    printf("Number after turning off the rightmost set bit: %u\n", result);

    return 0;
}
