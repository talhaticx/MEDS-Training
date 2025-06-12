#include <stdio.h>

int main(void){
    int x, y;
    printf("Enter 1st number: ");
    scanf("%d", &x);

    printf("Enter 2st number: ");
    scanf("%d", &y);

    __asm__ volatile("addl %1, %0" : "+r" (x) : "r" (y) : "cc");

    printf("\nSum is %d\n", x);
    return 0;
}