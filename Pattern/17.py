n = 5


def pattern(n):
    for i in range(1, n + 1):
        for j in range(i):
            print(chr((ord("A") + n) + j - i), end=" ")
        print()


pattern(n)
