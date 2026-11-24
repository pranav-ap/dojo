import std;

using namespace std;

void increment(int& num)
{
    // rvalues cannot enter here
    println("=> {} int&", __func__);

    println("num = {}", num);
    num++;
    println("num = {}", num);
}

void increment(const int& num)
{
    println("=> {} const int&", __func__);

    println("num = {}", num);
}

void increment(int&& num)
{
    // rvalues prefer (int&& num) over (const int& num)
    println("=> {} int&&", __func__);

    println("num = {}", num);
    num++;
    println("num = {}", num);
}

void passing_references()
{
    println("=> {}", __func__);

    int a = 5;
    increment(a);

    increment(5);
}

void explicit_move(int&& num)
{
    println("=> {}", __func__);

    // remember num is an lvalue in this func, so we need move()

    increment(move(num));
}

int main()
{
    passing_references();
    explicit_move(35);

    return 0;
}
