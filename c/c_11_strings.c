#include <stdio.h>
#include <string.h>


void one(void)
{
    // Actually "Hello, world!\0" behind the scenes
    char *s = "Hello, world!";

    printf("%s\n", s);
}

void two(void)
{
    char s[] = "Hello, world!";

    // Note that we’re using the format specifier %c to print a single character.
    for (int i = 0; i < 13; i++)
        printf("%c", s[i]);

    printf("\n");
}

void three(void)
{
    // can loop though string literal as well
    char *s = "Hello, world!";

    for (int i = 0; i < 13; i++)
        printf("%c", s[i]);

    printf("\n");
}

int my_strlen(char *s)
{
    int count = 0;

    while (s[count] != '\0')
        count++;

    return count;
}

int my_strlen_pointer_version(char *s)
{
    // Start scanning from the beginning of the string
    char *p = s;

    // Scan until we find the NUL character
    while (*p != '\0')
        p++;

    // Return the difference in pointers
    return p - s;
}

void str_copy_is_not_so_simple(void)
{
    char s[] = "Hello, world!";
    char *t;

    // This makes a copy of the pointer, not a copy of the string!
    t = s;

    // We modify t
    t[0] = 'z';

    // But printing s shows the modification!
    // Because t and s point to the same string!

    printf("%s\n", s);  // "zello, world!"
}

void str_copy(void)
{
    char s[] = "Hello, world!";
    char t[100];  // Each char is one byte, so plenty of room

    // This makes a copy of the string!
    /*
     * A mnemonic I use to remember this is that it’s
     * the order you would have put t and s if an assignment = worked for strings,
     * with the source on the right and the destination on the left.
     */

    strcpy(t, s);

    // We modify t
    t[0] = 'z';

    // And s remains unaffected because it's a different string
    printf("%s\n", s);  // "Hello, world!"

    // But t has been changed
    printf("%s\n", t);  // "zello, world!"
}

int main(void)
{
    // one();
    // two();
    // three();

    // str_copy_is_not_so_simple();
    str_copy();
}
