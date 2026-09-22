def unpack_list():
    # normal call with separate arguments
    assert list(range(3, 6)) == [3, 4, 5]

    # call with arguments unpacked from a list
    args = [3, 6]
    assert list(range(*args)) == [3, 4, 5]


def unpack_dict():
    def parrot(voltage, state='a stiff'):
        print(f'{voltage=}, {state=} ')

    d = {"state": "bleeding", "voltage": "four million"}
    parrot(**d)


def main():
    # unpack_list()
    unpack_dict()


if __name__ == '__main__':
    main()
