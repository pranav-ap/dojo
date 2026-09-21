#include <stdio.h>

int main(void)
{
    printf("sizeof(char)     = %zu byte\n",  sizeof(char));
    printf("\n");

    int   a = 999;
    printf("sizeof(int)      = %zu bytes\n", sizeof(int));
    printf("sizeof a         = %zu bytes\n", sizeof a);
    printf("sizeof(2 + 7)    = %zu bytes\n", sizeof(2 + 7));
    printf("\n");

    float b = 12.3;
    printf("sizeof(float)    = %zu bytes\n", sizeof(float));
    printf("sizeof(double)   = %zu bytes\n", sizeof(double));
    printf("sizeof 3.14      = %zu bytes\n", sizeof 3.14);
    printf("\n");

    int *p;
    printf("sizeof(int)      = %zu bytes\n", sizeof(int));
    printf("sizeof p         = %zu bytes\n", sizeof p);
    printf("sizeof *p        = %zu bytes\n", sizeof *p);
    printf("\n");

    printf("sizeof(double [48]) = %zu bytes\n", sizeof(double [48]));
    printf("\n");

    return 0;
}
