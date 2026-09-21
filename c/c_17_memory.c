#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void basics(void)
{
    // Allocate space for a single int (sizeof(int) bytes-worth):
    int *p = malloc(sizeof(int));

    if (p == NULL) {
        printf("Error allocating memory\n");
        return;
    }

    // Store something there
    *p = 12;

    // Print it: 12
    printf("%d\n", *p);

    // All done with that memory
    free(p);

    // ERROR: undefined behavior! Use after free()!
    //*p = 3490;
}

void init_memory(void)
{
    // Allocate space for 10 ints
    int *p = malloc(sizeof(int) * 10);

    // Assign them values 0 to 45
    for (int i = 0; i < 10; i++)
        p[i] = i * 5;

    // Print all values 0, 5, 10, 15, ..., 40, 45
    for (int i = 0; i < 10; i++)
        printf("%d\n", p[i]);

    // Free the space
    free(p);
}

void zero_init_memory(void)
{
    // CALLOC

    // Allocate space for 10 ints with calloc(), initialized to 0
    int *p = calloc(10, sizeof(int));

    // MALLOC + MEMSET

    // Allocate space for 10 ints with malloc()
    int *q = malloc(10 * sizeof(int));
    // set to 0
    memset(q, 0, 10 * sizeof(int));
}

void realloc_memory(void)
{
    // Allocate space for 20 floats
    // sizeof *p same as sizeof(float)
    float *p = malloc(sizeof *p * 20);

    // Assign them fractional values 0.0-1.0:
    for (int i = 0; i < 20; i++)
        p[i] = i / 20.0;

    // But wait! Let's actually make this an array of 40 elements
    float *new_p = realloc(p, sizeof *p * 40);

    // Check to see if we successfully reallocated
    if (new_p == NULL) {
        printf("Error reallocing\n");
        return;
    }

    // If we did, we can just reassign p
    p = new_p;

    // And assign the new elements values in the range 1.0-2.0
    for (int i = 20; i < 40; i++)
        p[i] = 1.0 + (i - 20) / 20.0;

    // Free the space
    free(p);
}

int main(void)
{
    realloc_memory();
    return 0;
}
