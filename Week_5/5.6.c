#include <stdio.h>

int main() {
    unsigned int num;
    int position = -1;

    printf("Enter a number: ");
    scanf("%u", &num);

    while (num > 0) {
        if (num & 1) {
            if (position == -1) {
                position = 0;
            }
            break;
        }
        num >>= 1;
        position++;
    }

    printf("Position of the only set bit: %d\n", position);

    return 0;
}
