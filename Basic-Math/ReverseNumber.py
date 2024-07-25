def solve1(n):
    ans = 0

    while n != 0:
        units = n % 10
        n //= 10
        ans = ans * 10 + units

    print(ans)


solve1(1234)
