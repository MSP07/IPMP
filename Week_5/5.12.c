#include <stdio.h>

int main() {
    char ch;

    printf("Enter a letter: ");
    scanf("%c", &ch);

    if (ch >= 'a' && ch <= 'z') {
        int position = ch - 'a' + 1;
        printf("Position of '%c' in the alphabet: %d\n", ch, position);
    } else if (ch >= 'A' && ch <= 'Z') {
        int position = ch - 'A' + 1;
        printf("Position of '%c' in the alphabet: %d\n", ch, position);
    } else {
        printf("Error: '%c' is not a letter.\n", ch);
    }

    return 0;
}
