#include <stdio.h>
#include <math.h>

double sqrt_binary_search(double x) {
    if (x < 0) {
        printf("Cannot compute square root of a negative number.\n");
        return -1;
    }
    if (x == 0 || x == 1) {
        return x;
    }

    double low = 0, high = x;
    double precision = 1e-6;  // Precision level for the result

    while (high - low > precision) {
        double mid = (low + high) / 2;
        if (mid * mid == x) {
            return mid;
        } else if (mid * mid < x) {
            low = mid;
        } else {
            high = mid;
        }
    }

    return (low + high) / 2;
}

int main() {
    for (float i = 0; i < 16; i++){
        printf("Square root of %.2f is %.6f\n", i, sqrt_binary_search(i));
    }
    return 0;
}
