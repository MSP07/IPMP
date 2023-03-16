#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

int main() {
    char str[MAX_SIZE];
    int freq[256] = {0}, max_length = 0, length = 0, start_index = 0, i;

    printf("Enter a string: ");
    gets(str);

    for(i=0; str[i]!='\0'; i++) {
        if(freq[str[i]] == 0) {
            freq[str[i]] = 1;
            length++;
        }
        else {
            if(length > max_length) {
                max_length = length;
            }
            while(freq[str[i]] != 0) {
                freq[str[start_index]] = 0;
                start_index++;
                length--;
            }
            freq[str[i]] = 1;
            length++;
        }
    }

    if(length > max_length) {
        max_length = length;
    }

    printf("Length of the longest substring without repeating characters: %d\n", max_length);

    return 0;
}
