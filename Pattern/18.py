n = 5


def pattern(n):
    for i in range(n):
        print("*" * (n - i), end="")
        print(" " * (i * 2), end="")
        print("*" * (n - i), end="")
        print()

    for i in range(1, n + 1):
        print("*" * i, end="")
        print(" " * 2 * (n - i), end="")
        print("*" * i, end="")
        print()


pattern(n)
