#include <stdio.h>

void printBinary(unsigned int n) {
    for (int i = sizeof(unsigned int) * 8 - 1; i >= 0; i--) {
        if ((n >> i) & 1) {
            printf("1");
        } else {
            printf("0");
        }
    }
}

int main() {
    unsigned int n;

    printf("Enter a non-negative integer: ");
    scanf("%u", &n);

    printf("Binary representation: ");
    printBinary(n);
    printf("\n");

    return 0;
}
