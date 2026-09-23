class Quantity:
    # owner is the managed class
    # name is the name of the attribute of owner
    def __set_name__(self, owner, storage_name):
        self.storage_name = storage_name

    def __set__(self, instance, value):
        if value > 0:
            instance.__dict__[self.storage_name] = value
        else:
            msg = f'{self.storage_name} must be > 0'
            raise ValueError(msg)

    def __get__(self, instance, owner):
        """
        Implementing __get__ is not necessary because the name of the storage attribute
        matches the name of the managed attribute.
        """
        if instance is None:
            return self
        else:
            return instance.__dict__[self.storage_name]


class LineItem:
    weight = Quantity()
    price = Quantity()

    def __init__(self, description, weight, price):
        self.description = description
        self.weight = weight
        self.price = price

    def subtotal(self):
        return self.weight * self.price


def main():
    l = LineItem('hello', 1, 2)
    print(l.subtotal())


if __name__ == '__main__':
    main()
