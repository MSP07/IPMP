#include <stdio.h>
#include <stdlib.h>

void generateStrings(int n, int k, int A[]) {
    if (n == 0) {
        for (int i = 0; i < n; i++) {
            printf("%d", A[i]);
        }
        printf("\n");
    } else {
        for (int j = 0; j < k; j++) {
            A[n-1] = j;
            generateStrings(n-1, k, A);
        }
    }
}

int main() {
    int n, k;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("Enter the value of k: ");
    scanf("%d", &k);

    int A[n];
    generateStrings(n, k, A);

    return 0;
}
