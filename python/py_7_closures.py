a = 35

def out():
    global a
    a = 25

    def inner1():
        def inner2():
            # does not work
            # nonlocal a
            a = 30

def hell():
    a = 1
    def deeper():
        print(a)

    deeper()

def main():
    hell()


if __name__ == '__main__':
    main()
