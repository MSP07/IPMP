#include <stdio.h>

int main() {
    char ch;

    printf("Enter a character: ");
    scanf("%c", &ch);

    if (ch >= 'A' && ch <= 'Z') {
        ch = ch | 0x20;
    }

    printf("Lowercase: %c\n", ch);

    return 0;
}
