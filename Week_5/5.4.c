#include <stdio.h>

int main() {
    unsigned int num;
    int count = 0;

    printf("Enter a number: ");
    scanf("%u", &num);

    while (num > 0) {
        if (num & 1) {
            count++;
        }
        num >>= 1;
    }

    printf("Number of set bits: %d\n", count);

    return 0;
}
