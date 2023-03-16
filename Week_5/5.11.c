#include <stdio.h>

int main() {
    char ch;

    printf("Enter a character: ");
    scanf("%c", &ch);

    if (ch >= 'a' && ch <= 'z') {
        ch = ch & ~0x20;
    }

    printf("Uppercase: %c\n", ch);

    return 0;
}
