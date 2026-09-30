import std;

using namespace std;

int main()
{
    int nums[] = {1, 2, 3};

    cout << nums << endl;
    cout << &nums[0] << endl;

    cout << nums[2] << endl;
    cout << *(nums + 2) << endl;

    return 0;
}
