#include <stdio.h>

struct car {
    char *name;
    float price;
    int speed;
};

void set_price(struct car *c, float new_price);


int main(void)
{
    struct car saturn = {"Saturn SL/2", 16000.99, 175};

    // Similar to array initializers, any missing field designators are initialized to zero
    struct car saturn2 = {.speed=175, .name="Saturn SL/2"};

    printf("Name:      %s\n", saturn.name);
    printf("Price:     %f\n", saturn.price);
    printf("Top Speed: %d km\n", saturn.speed);

    // Pass a pointer to this struct car, along with a new,
    // more realistic, price:
    set_price(&saturn, 799.99);

    printf("Price: %f\n", saturn.price);
}

void set_price(struct car *c, float new_price) {
    // ERROR!!
    // c.price = new_price;

    // Works, but non-idiomatic
    // (*c).price = new_price;

    c->price = new_price;
}
