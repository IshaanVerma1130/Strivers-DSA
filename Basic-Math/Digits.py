import math


n = 12345


def solve1(n):
    count = 0

    while n != 0:
        n = n // 10
        count += 1

    print(count)


def solve2(n):
    print(math.floor(math.log10(n) + 1))


solve1(n)
solve2(n)
