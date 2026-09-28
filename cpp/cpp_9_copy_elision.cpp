import std;

using namespace std;


struct Foo
{
    Foo()
    {
        println("default");
    }

    Foo(const Foo&)
    {
        println("copy");
    }

    Foo(Foo&&)
    {
        println("move");
    }
};

Foo make()
{
    return Foo();
}

int main()
{
    /*
    Without elision you'd see: default, move (or copy), move…
    With elision (which is what actually happens) you see just: default. No copy, no move.
    */

    Foo f = make();
}
