#include <stdio.h>

int countTrailingZeros(unsigned int n) {
    if (n == 0) return 32;

    int count = 0;
    while ((n & 1) == 0) {
        count++;
        n >>= 1;
    }
    return count;
}

// Function to print binary
void printBinary(unsigned int n) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
        if (i % 4 == 0) printf(" ");
    }
}

int main() {
    unsigned int num;

    printf("Enter a number: ");
    scanf("%u", &num);

    int tz = countTrailingZeros(num);

    printf("\nBinary Representation:\n");
    printBinary(num);

    printf("\n\nTrailing Zeros:\n");
    printf("Decimal: %d\n", tz);

    printf("Binary : ");
    printBinary(tz);
    printf("\n");

    return 0;
}
