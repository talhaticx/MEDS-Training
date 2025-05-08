#include <stdio.h>
#include <math.h>

// Function to compute exp(x) using Taylor series
float exp_taylor(float x, int terms) {
    float result = 1.0f;     // x^0 / 0!
    float factorial = 1.0f;
    float power = 1.0f;

    for (int n = 1; n < terms; n++) {
        power *= x;          // x^n
        factorial *= n;      // n!
        result += power / factorial;
    }

    return result;
}

int main(void) {
    printf("Self-implemented exp(x):\n");
    for (int x = 0; x < 10; x++) {
        printf("x = %d: %.6f\n", x, exp_taylor(x, 30));
    }

    printf("\nBuilt-in exp(x):\n");
    for (int x = 0; x < 10; x++) {
        printf("x = %d: %.6f\n", x, exp(x));
    }

    printf("\nPrecision Check:\n");
    for (int terms = 0; terms <= 30; terms += 3) {
        printf("\nterms = %d:\n", terms);
        for (int x = 0; x < 5; x++) {
            printf("exp(%d, %d) = %.6f  ", x, terms, exp_taylor(x, terms));
        }
        printf("\n");
    }

    return 0;
}
