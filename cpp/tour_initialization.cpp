import std;

using namespace std;

void equal_and_curly()
{
    println("=> {}", __func__);

    double d1 = 2.3;
    println("d1 = {}", d1);

    double d2 {2.3};
    println("d2 = {}", d2);

    double d3 = {2.3}; // with {}, the = is optional
    println("d3 = {}", d3);

    vector<int> lst1 {1, 2, 3};
    println("lst1 = {}", lst1);

    vector<int> lst2 = {1, 2, 3};
    println("lst2 = {}", lst2);
}

void implicit_narrowing_conversions_loses_info()
{
    println("=> {}", __func__);

    int integer = 1.0;
    println("integer = {}", integer);

    // compile error
    // int another_integer {1.0};
}

void default_initialization()
{
    println("=> {}", __func__);

    int a;
    println("integer = {}", a);

    double b;
    println("double = {}", b);

    struct Player
    {
        int a;
    };

    Player p;
    println("integer p.a = {}", p.a);

}

void zero_initialization()
{
    println("=> {}", __func__);

    int a {};
    println("integer = {}", a);

    double b {};
    println("double = {}", b);

    struct Player
    {
        int a;
    };

    Player p {};
    println("integer p.a = {}", p.a);
}

void designated_initializers()
{
    println("=> {}", __func__);

    struct Player
    {
        int a;
        double b; // gets zero initialized
    };

    Player p {
        .a = 10,
    };

    println("integer p.a = {}", p.a);
    println("double p.b = {}", p.b);
}


const string& get_name()
{
    static const string name { "Jon" };
    return name;
}

void auto_usage()
{
    println("=> {}", __func__);

    // infers i as int
    auto i { 5 };
    println("integer i = {}", i);

    // don't skip the * symbol. gets confusing without it
    const auto* const pi = &i;
    println("pi = {:p}", (void*)pi);

    // auto (by value) — const and & are STRIPPED
    // type of a is: std::string  (a copy; not const, not a reference)
    auto a = get_name();
    a = string("a");
    println("a = {}", a);

    // const auto& — const and & KEPT
    const auto& b = get_name();
    // type of b is: const std::string&  (no copy)
    // b = "x";                    // ERROR — b is const
    println("b = {}", b);          // Jon

    // decltype does not strip
    decltype(get_name()) c = get_name();
    println("c = {}", c);          // Jon
}

int main()
{
    auto_usage();

    return 0;
}
