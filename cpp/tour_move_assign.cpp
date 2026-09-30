import std;

using namespace std;

class Gadget
{
    public:
        int score;

        Gadget() : score(0) {}
};

class Widget
{
    public:
    int age;
    Gadget* gadget;

    Widget() : age(0), gadget(new Gadget()) {}

    // copy & move are the same thing for ints
    // dont forget to set nullptr
    Widget(Widget&& other) noexcept : age(move(other.age)), gadget(exchange(other.gadget, nullptr)) {}

    Widget& operator=(Widget&& other) noexcept
    {
        age = move(other.age);

        // dont forget to set nullptr
        gadget = exchange(other.gadget, nullptr);

        return *this;
    }
};

int main()
{
    Widget w;
    println("widget 1 - {}, {}", w.age, (void*)w.gadget);
    println();

    Widget w2 = move(w);
    println("widget 2 - {}, {}", w2.age, (void*)w2.gadget);
    println("widget 1 - {}, {}", w.age, (void*)w.gadget);
    println();

    Widget w3;
    println("widget 3 - {}, {}", w3.age, (void*)w3.gadget);
    println("widget 2 - {}, {}", w2.age, (void*)w2.gadget);
    println();

    w3 = move(w2);
    println("widget 3 - {}, {}", w3.age, (void*)w3.gadget);
    println("widget 2 - {}, {}", w2.age, (void*)w2.gadget);

    return 0;
}
