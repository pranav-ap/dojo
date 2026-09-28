import std;

using namespace std;

void show(const int& num)
{
    println("=> {}", __func__);
    println("show num : {}", num);
}

void show(const int&& num)
{
    println("=> {}", __func__);
    println("show rvalue num : {}", num);
}

void increment(int& num)
{
    println("=> {}", __func__);

    println("show num : {}", num);
    num++;
    println("show num : {}", num);
}

void increment(int&& num)
{
    println("=> {}", __func__);

    println("show rvalue num : {}", num);
    num++;
    println("show rvalue num : {}", num);
}

void explicit_move(int&& num)
{
    println("=> {}", __func__);

    // remember num is an lvalue in this func, so we need move()

    increment(move(num));
}

int main()
{
    int num = 5;
    show(num);
    show(25);

    num = 5;
    increment(num);
    increment(25);

    explicit_move(10);

    return 0;
}
