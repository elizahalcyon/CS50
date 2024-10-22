# TODO
from cs50 import get_int

def main():
    height = get_height()
    m = 1
    i = height - 1

    for j in range(height):
        print(" " * i, "#" * m, sep='')
        m += 1
        i -= 1


def get_height():
    while True:
        m = get_int("Enter Height 1-8: ")
        if m < 1 or m > 8:
            print("Invalid Height")
            main()
        return m

main()