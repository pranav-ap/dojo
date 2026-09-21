#include <stdio.h>

void basics(void)
{
    int i;
    // Declare an array of 4 floats
    float f[4] = {3.14, 1.41, 1.61, 2.71};

    for (i = 0; i < 4; i++)
    {
        printf("%f\n", f[i]);
    }

    // size can be left out
    float g[] = {3.14, 1.41, 1.61, 2.71};

    // others are init to 0
    int a[5] = {22, 37, 3490};
    // is the same as:
    int b[5] = {22, 37, 3490, 0, 0};

    // set specific array elements
    int c[10] = {0, 11, 22, [5]=55, 66, 77};
    // 0 11 22 0 0 55 66 77 0 0

    // Make a 3x3 identity matrix
    int d[3][3] = {[0][0]=1, [1][1]=1, [2][2]=1};
}

void length_1_fails(int x[12])
{
    printf("Array Length is lost! \n");
    // 8?! What happened to 48?
    printf("sizeof x = %zu bytes\n", sizeof x);
}

void length_1(void)
{
    int x[12];  // 12 ints

    // 48 total bytes
    printf("sizeof x = %zu bytes\n", sizeof x);
    // 4 bytes per int
    printf("sizeof(int) = %zu bytes\n", sizeof(int));
    // 48 / 4 = 12 ints
    printf("sizeof x / sizeof(int) = %zu elements\n", sizeof x / sizeof(int));

    length_1_fails(x);
}

void pointer_to_array(void)
{
    int a[] = {11, 22, 33, 44, 55};
    int *p;

    p = &a[0];  // p points to the array
                // Well, to the first element, actually

    // is the same as:

    p = a;      // p points to the array
                // but much nicer-looking!

    printf("%d\n", *p);  // Prints "11"
}

int main(void)
{
    // basics();
    // length_1();
    pointer_to_array();
    return 0;
}
