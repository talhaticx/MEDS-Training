#include <stdio.h>

#define INT_MAX 2147483647
#define INT_MIN (-2147483648)


int main(void){
    int overflow_int = INT_MAX;
    int underflow_int = INT_MIN;

    int overflow_res = overflow_int + 1;
    int underflow_res = underflow_int - 1;

    printf("Overflow Illustration:\n");
    printf("INT_MAX        = %d\n", overflow_int);
    printf("INT_MAX + 1    = %d (Overflow occurred)\n\n", overflow_res);

    printf("Underflow Example:\n");
    printf("INT_MIN        = %d\n", underflow_int);
    printf("INT_MIN - 1    = %d (Underflow occurred)\n", underflow_res);

    return 0;
}