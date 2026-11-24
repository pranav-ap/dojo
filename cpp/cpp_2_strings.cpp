import std;

using namespace std;

void show(const char* s)
{
    println("const char* {}", s);
}

void show(string s)
{
    println("string {}", s);
}

int main()
{
    string s {"jon"};
    show(s);

    return 0;
}
