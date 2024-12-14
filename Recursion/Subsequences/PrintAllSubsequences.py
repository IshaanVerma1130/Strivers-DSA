def recur(ip, op):
    if len(ip) == 0:
        print(op)
        return

    op1 = op + ip[0]
    op2 = op

    ip = ip[1:]

    recur(ip, op2)
    recur(ip, op1)


def optimal(s):
    ip = s
    op = ""
    recur(ip, op)


optimal("abc")
