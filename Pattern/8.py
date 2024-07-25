n = 5


def pattern(n):
    maxLim = n * 2 - 1
    for i in range((n * 2) - 1, 0, -2):
        sides = (maxLim - i) // 2
        print(" " * sides, end="")
        print("*" * i, end="")
        print(" " * sides, end="")
        print()


pattern(n)
