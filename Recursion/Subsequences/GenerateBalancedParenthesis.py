def recur(op, open, close):
    if open == 0 and close == 0:
        print(op)
        return

    if open != 0:
        op1 = op + "("
        recur(op1, open - 1, close)

    if close > open:
        op2 = op + ")"
        recur(op2, open, close - 1)


def optimal(k):
    op = ""
    open = k
    close = k
    recur(op, open, close)


optimal(3)
