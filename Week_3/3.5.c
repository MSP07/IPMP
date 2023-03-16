#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i;

    printf("Enter a string: ");
    gets(str);

    printf("Reverse of the string: ");
    for(i=strlen(str)-1;i>=0;i--) {
        printf("%c", str[i]);
    }

    return 0;
}
