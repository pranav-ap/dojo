import abc
import typing


class Park:
    a = 10


class MyABC(abc.ABC):
    @classmethod
    @abc.abstractmethod # must be the innermost decorator
    def an_abstract_classmethod(cls):
        pass


class Student(MyABC):
    @classmethod
    def an_abstract_class_method(cls):
        print('hi')


@typing.runtime_checkable
class Quackable(typing.Protocol):
    def quack(self) -> None:
        pass


class Duck:
    def quack(self):
        print("Quack!")


def run_quack(obj: Quackable):
    obj.quack()


def main():
    run_quack(Duck())  # Works!

    # Without runtime_checkable, that's a TypeError.
    isinstance(Duck(), Quackable)


if __name__ == '__main__':
    main()
