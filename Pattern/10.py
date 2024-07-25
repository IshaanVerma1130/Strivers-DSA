n = 5


def pattern(n):
    its = n * 2 - 1

    for i in range(1, its + 1):
        if i == n:
            print("*" * i)

        if i > n:
            spaces = i - n
            stars = n - spaces
            print("*" * stars, end="")
            print(" " * spaces)

        elif i < n:
            spaces = n - i
            stars = i
            print("*" * stars, end="")
            print(" " * spaces)


pattern(n)
