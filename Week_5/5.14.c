#include <stdio.h>

int main() {
    int num;

    printf("Enter an integer: ");
    scanf("%d", &num);

    if ((num & (num - 1)) == 0 && (num | (num / 2)) == num) {
        printf("%d is a power of 4.\n", num);
    } else {
        printf("%d is not a power of 4.\n", num);
    }

    return 0;
}