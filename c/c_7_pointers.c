#include <stdio.h>
#include <stddef.h>
#include <stdint.h>

void basics(void)
{
    int i = 10;
    // p is a pointer, but is uninitialized and points to garbage
    int *p;
    // p is assigned the address of i
    p = &i;

    printf("The value of i is %d\n", i);
    printf("And its address is %p\n", (void *)p);
    printf("\n");

    i = 20;
    printf("The new value of i is %d\n", i);
    printf("The new value of *p is %d\n", *p);
}

void increment(int *p)
{
    *p = *p + 1;
}

void pass_by_reference(void)
{
    int i = 10;

    printf("i is %d\n", i);  // prints "10"
    increment(&i);
    printf("i is %d\n", i);  // prints "11"!
}

void difference(void)
{
    int cats[100];

    int *f = cats + 20;
    int *g = cats + 60;

    ptrdiff_t d = g - f;  // difference is 40

    printf("%td\n", d);  // Print decimal: 40
}

void pointers_as_ints(void)
{
    int a = 4;
    int *p = &a;

    // warning - truncates int* (8 bytes) to int (4 bytes) on 64-bit system
    // int b = (int) p;

    // safe, no truncation
    uintptr_t b = (uintptr_t) p;

    printf("%p\n", (void *)p);
}

int main(void)
{
    // basics();
    pass_by_reference();
    return 0;
}
