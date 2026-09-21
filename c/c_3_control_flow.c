#include <stdio.h>
#include <stdbool.h>

void loops (void)
{
    // Using a while statement:

    int i = 10;

    while (i < 10) {
        printf("while: i is %d\n", i);
        i++;
    }

    // Using a do-while statement:

    i = 10;

    do {
        printf("do-while: i is %d\n", i);
        i++;
    } while (i < 10);
}

void conditionals(void)
{
    /*
     * IF ELSE STATEMENT
     */
    bool x = true;

    if (!x)
    {
        printf("x is true!\n");
    }
    else if (1 < 10 && 2 > 20)
    {
        printf("Doing something!\n");
    }
    else
    {
        printf("x is false!\n");
    }

    /*
     * TERNARY OPERATOR
     *
     * It’s important to note that the ternary operator isn’t flow control
     * like the if statement is. It’s just an expression that evaluates to a value.
     */

    int y = 1 > 10 ? 17 : 37;
    printf("y is %d\n", y);

    /*
     * SWITCH STATEMENT
     *
     * Evaluates an expression to an integer value,
     * jumps to the case that corresponds to that value.
     * Execution resumes from that point.
     * If a break statement is encountered, then execution jumps out of the switch.
     *
     * Well, what happens if we don’t break?
     * Turns out we just keep on going into the next case!
     *
     * Don’t use floating point or string types in there.
     * One loophole-ish thing here is that you can use
     * character types because those are secretly integers themselves.
     */

    int goat_count = 2;

    switch (goat_count) {
        case 0:
            printf("You have no goats.\n");
            break;

        case 1:
            printf("You have a singular goat.\n");
            break;

        case 2:
            printf("You have a brace of goats.\n");
            break;

        default:
            printf("You have a bona fide plethora of goats!\n");
            break;
    }
}

int main(void)
{
    conditionals();
    loops();

    return 0;
}
