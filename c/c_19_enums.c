#include <stdio.h>

void basics(void)
{
    enum resource {
        SHEEP,
        WHEAT,
        WOOD,
        BRICK,
        ORE
    };

    enum resource r = BRICK;

    if (r == BRICK)
    {
        printf("I'll trade you a brick for two sheep.\n");
    }
}

void mash_together(void)
{
    typedef enum {
        SHEEP,
        WHEAT,
        WOOD,
        BRICK,
        ORE
    } RESOURCE;

    RESOURCE r = BRICK;
}

int main(void)
{
    basics();
    mash_together();
}
