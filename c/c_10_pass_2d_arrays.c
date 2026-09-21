#include <stdio.h>

/*
 * The compiler really only needs the second dimension so
 * it can figure out how far in memory to skip for each increment of the first dimension.
 * In general, it needs to know all the dimensions except the first one.
 */
void print_2D_array(int a[2][3])
{
    for (int row = 0; row < 2; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            printf("%d ", a[row][col]);
        }

        printf("\n");
    }
}

int main(void)
{
    int x[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    print_2D_array(x);
}
