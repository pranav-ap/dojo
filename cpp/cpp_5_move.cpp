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

int main()
{
    int num = 5;
    show(num);
    show(25);

    num = 5;
    increment(num);
    increment(25);

    return 0;
}
