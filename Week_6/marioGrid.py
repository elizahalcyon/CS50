def main():
    height = get_height()
    width = get_width()

    for i in range(height):
        print("#" * width)
        """ for j in range(width):
            print("#", end="")
        print() """


def get_height():
    while True:
        try:
            m = int(input("Height: "))
            if m > 0:
                return m
        except ValueError:
            print("Not an integer")


def get_width():
    while True:
        try:
            n = int(input("Width: "))
            if n > 0:
                return n
        except ValueError:
            print("Not an integer")


main()