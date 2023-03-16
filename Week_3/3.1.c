#include <stdio.h>

void generateStrings(int n, char A[]) {
    if (n == 0) {
        printf("%s\n", A);
    } else {
        A[n-1] = '0';
        generateStrings(n-1, A);
        A[n-1] = '1';
        generateStrings(n-1, A);
    }
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    char A[n+1];
    A[n] = '\0';
    generateStrings(n, A);

    return 0;
}
