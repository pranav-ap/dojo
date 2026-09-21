#include <stdio.h>

void increment(int a)
{
    a++;
}

int main(void)
{
    int i = 10;

    // pass by value
    increment(i);

    // What does this print?
    printf("i == %d\n", i);
}
