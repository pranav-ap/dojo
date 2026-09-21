#include <stdio.h>

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

int main(void)
{
    // basics();
    pass_by_reference();
    return 0;
}
