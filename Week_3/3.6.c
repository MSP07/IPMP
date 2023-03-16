#include <stdio.h>
#include <ctype.h>

int main() {
    char str[100];
    int alphabets = 0, digits = 0, special = 0, i;

    printf("Enter a string: ");
    gets(str);

    for(i=0;str[i]!='\0';i++) {
        if(isalpha(str[i])) {
            alphabets++;
        }
        else if(isdigit(str[i])) {
            digits++;
        }
        else {
            special++;
        }
    }

    printf("Total number of alphabets: %d\n", alphabets);
    printf("Total number of digits: %d\n", digits);
    printf("Total number of special characters: %d\n", special);

    return 0;
}
