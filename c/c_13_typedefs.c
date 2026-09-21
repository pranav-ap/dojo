#include <stdio.h>


void basic(void)
{
    struct animal {
        char *name;
        int leg_count, speed;
    };

    //  original name      new name
    //            |         |
    //            v         v
    //      |-----------| |----|
    typedef struct animal animal;

    struct animal y;  // This works
    animal z;         // This also works because "animal" is an alias
}

void mash_together(void)
{
    //  original name
    //            |
    //            v
    //      |-----------|
    typedef struct animal {
        char *name;
        int leg_count, speed;
    } animal;                         // <-- new name

    struct animal y;  // This works
    animal z;         // This also works because "animal" is an alias
}

void anonymous_struct(void)
{
    //  Anonymous struct! It has no name!
    //         |
    //         v
    //      |----|
    typedef struct {
        char *name;
        int leg_count, speed;
    } animal;                         // <-- new name

    //struct animal y;  // ERROR: this no longer works -- no such struct!
    animal z;           // This works because "animal" is an alias
}

int main(void)
{
}
