def inf(func):
    print("Information about", func.__name__)

    def details(*args):
        print("Execute function ", func.__name__, " with the argument(s)")
        return func(*args)

    return details


def basics():
    def my_func(*params):
        print(params)

    my_func = inf(my_func)

    my_func("Hello", "Pythonistas!")


def sugar():
    @inf
    def my_func(*params):
        print(params)

    my_func("Hello", "Pythonistas!")


def main():
    # basics()
    sugar()


if __name__ == "__main__":
    main()
