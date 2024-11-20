n = 5


def pattern(n):
    for i in range(1, 2 * n):
        if i == n:
            for j in range(2 * n):
                print("*", end="")
        elif i < n:
            for j in range(i):
                print("*", end="")
            for j in range(2 * (n - i)):
                print(" ", end="")
            for j in range(i):
                print("*", end="")
        elif i > n:
            for j in range(2 * n - i):
                print("*", end="")
            for j in range(2 * (i - n)):
                print(" ", end="")
            for j in range(2 * n - i):
                print("*", end="")

        print()


pattern(n)
