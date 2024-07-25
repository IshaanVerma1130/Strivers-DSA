n = 5


def pattern(n):
    for i in range(2 * n - 1):
        for j in range(2 * n - 1):
            top = i
            bottom = (2 * n - 1) - 1 - i
            left = j
            right = (2 * n - 1) - 1 - j
            print(n - min([top, left, bottom, right]), end="")
        print()


pattern(n)
