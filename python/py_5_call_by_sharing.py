def f(a, b):
    a += b
    return a


def pass_ints():
    x = 1
    y = 2

    print(f'{(x, y)=}')
    print(f'{f(x, y)=}')
    print(f'{(x, y)=}')


def pass_lists():
    x = [1, 2]
    y = [3, 4]

    print(f'{(x, y)=}')
    print(f'{f(x, y)=}')
    print(f'{(x, y)=}')


def main():
    pass_ints()
    print('-----')
    pass_lists()


if __name__ == "__main__":
    main()
