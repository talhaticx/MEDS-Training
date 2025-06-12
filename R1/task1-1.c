#include <stdio.h>
#include <stdint.h>

// Declare function before main
void print_binary(short n);

int main(void) {
    short input;
    int output;

    printf("Enter a number: ");
    scanf("%hd", &input);

    output = ~input + 1;

    printf("Original:\n");
    printf("Decimal: %hd\tBinary: ", input);
    print_binary(input);
    printf("\n\n");

    printf("Two's Complement:\n");
    printf("Decimal: %hd\tBinary: ", (short)output);
    print_binary((short)output);
    printf("\n");

    return 0;
}

void print_binary(short n) {
    for (int i = 15; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
        if (i % 4 == 0 && i != 0) printf(" ");
    }
}
