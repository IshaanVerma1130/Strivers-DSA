def fun(arr, target):
    n = len(arr)

    dp = {}  # (i, t): val

    def recur(i, t):
        if i < 0:
            if t == 0:
                return 1
            else:
                return 0

        if (i, t) in dp:
            return dp[(i, t)]

        pos = recur(i - 1, t + arr[i])
        neg = recur(i - 1, t - arr[i])

        dp[(i, t)] = pos + neg

        return pos + neg

    return recur(n - 1, target)
