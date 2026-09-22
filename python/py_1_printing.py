def printing():
    print('Hello \t :)')
    print(r'Hello \t :)')

    name = 'sam'
    print(f'Hello {name}')

    # the \ removes the newline
    greeting = """\
Hello!
How are you?
    """

    print(greeting)


def main():
    printing()


if __name__ == '__main__':
    main()
