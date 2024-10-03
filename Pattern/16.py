n = 5


def pattern(n):
    for i in range(n):
        for j in range(n - i - 1):
            print(" ", end="")

        ch = "A"
        bp = (2 * i + 1) // 2
        for j in range(2 * i + 1):
            print(ch, end="")

            if j < bp:
                ch = chr(ord(ch) + 1)
            elif j >= bp:
                ch = chr(ord(ch) - 1)

        for j in range(n - i - 1):
            print(" ", end="")

        print()


pattern(n)
