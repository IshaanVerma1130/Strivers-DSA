n = 5


def pattern(n):
    start = 1
    for i in range(1, n + 1):
        for j in range(i):
            print(start, end=" ")
            start += 1
        print()


pattern(n)
