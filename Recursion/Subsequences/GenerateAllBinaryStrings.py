def recur(k, out):
    if k == 0:
        print(out)
        return

    recur(k - 1, out + "0")
    recur(k - 1, out + "1")


def optimal(k: int):
    recur(k, "")


optimal(3)
