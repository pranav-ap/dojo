#include <stdio.h>

int main(void)
{
    int a[5] = {11, 22, 33, 44, 55};

    int *p = &a[0];  // Or "int *p = a;" works just as well

    printf("%d\n", *p);  // Prints 11
    printf("%d\n", *(p + 0));  // Prints 11
    printf("%d\n", *(p + 1));  // Prints 22!!
}
