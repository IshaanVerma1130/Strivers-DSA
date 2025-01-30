def optimal(cap, val, wt):
    n = len(val)

    dp = [[-1] * (cap + 1) for _ in range(n)]

    def recur(i, c):
        if i == 0:
            if wt[i] <= c:
                return val[i]
            return 0

        if dp[i][c] != -1:
            return dp[i][c]

        notTake = recur(i - 1, c)
        take = 0
        if wt[i] <= c:
            take = val[i] + recur(i - 1, c - wt[i])

        dp[i][c] = max(take, notTake)

        return max(take, notTake)

    return recur(n - 1, cap)


def tab(cap, val, wt):
    n = len(val)

    dp = [[0] * (cap + 1) for _ in range(n)]

    for w in range(wt[0], cap + 1):
        dp[0][w] = val[0]

    for i in range(1, n):
        for w in range(cap + 1):
            notTake = dp[i - 1][w]
            take = 0
            if wt[i] <= w:
                take = val[i] + dp[i - 1][w - wt[i]]

            dp[i][w] = max(take, notTake)

    return dp[n - 1][cap]


print(tab(6, [30, 40, 50], [3, 2, 5]))
