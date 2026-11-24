import std;

using namespace std;

void print_array(int arr[])
{
    println("{}", sizeof(arr));
}

void decay_arrays()
{
    int arr[] = {1, 2, 3};

    // sizeof(int) * 3 = 12 bytes
    println("{}", sizeof(arr));

    // sizeof(int*) = 8 bytes
    print_array(arr);
}

void number_of_elements()
{
    int array[5];

    println("{}", sizeof(array) / sizeof(array[0]));
    println("{}", size(array));
}

int main()
{
    decay_arrays();

    return 0;
}
