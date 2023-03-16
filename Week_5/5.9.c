#include <stdio.h>

int main() {
    int num1, num2;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    while (num2 != 0) {
        int carry = num1 & num2;

        num1 = num1 ^ num2;

        num2 = carry << 1;
    }

    printf("Sum: %d\n", num1);

    return 0;
}
