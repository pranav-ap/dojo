#include <stdio.h>

int main(void)
{
    printf("sizeof(char)     = %zu byte\n",  sizeof(char));

    int   a = 999;
    printf("sizeof(int)      = %zu bytes\n", sizeof(int));
    printf("sizeof a         = %zu bytes\n", sizeof a);
    printf("sizeof(2 + 7)    = %zu bytes\n", sizeof(2 + 7));

    float b = 12.3;
    printf("sizeof(float)    = %zu bytes\n", sizeof(float));
    printf("sizeof(double)   = %zu bytes\n", sizeof(double));
    printf("sizeof 3.14      = %zu bytes\n", sizeof 3.14);

    return 0;
}
