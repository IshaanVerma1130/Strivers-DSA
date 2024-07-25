n = 5


def pattern(n):
    integer = 1
    for i in range(n):
        if i % 2 == 0:
            integer = 1
        else:
            integer = 0
        for j in range(i + 1):
            print(integer, " ", end="")
            integer = 1 - integer
        print()


pattern(n)
