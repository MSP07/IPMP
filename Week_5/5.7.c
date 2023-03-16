#include <stdio.h>

int main() {
    unsigned int num;

    printf("Enter a number: ");
    scanf("%u", &num);

    if (num && !(num & (num - 1))) {
        printf("%u is a power of 2\n", num);
    } else {
        printf("%u is not a power of 2\n", num);
    }

    return 0;
}
