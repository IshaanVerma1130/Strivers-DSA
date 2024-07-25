n = 5


def pattern(n):
    maxLim = 5 * 2 - 1
    for i in range(1, n * 2, 2):
        sides = (maxLim - i) // 2
        print(" " * sides, end="")
        print("*" * i, end="")
        print(" " * sides, end="")
        print()


pattern(n)
