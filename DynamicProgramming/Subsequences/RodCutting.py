def fun(prices):
    n = len(prices)

    dp = [[-1] * (n + 1) for _ in range(n)]

    def recur(i, c):
        if i == 0:
            if 1 <= c:
                return prices[0] * c
            else:
                return 0

        if dp[i][c] != -1:
            return dp[i][c]

        notTake = recur(i - 1, c)
        take = 0
        if c >= (i + 1):
            take = prices[i] + recur(i, c - (i + 1))
        dp[i][c] = max(take, notTake)
        return max(take, notTake)

    return recur(n - 1, n)


def tab(prices):
    n = len(prices)

    dp = [[0] * (n + 1) for _ in range(n)]

    for c in range(1, n + 1):
        dp[0][c] = prices[0] * c

    for i in range(1, n):
        for c in range(n + 1):
            notTake = dp[i - 1][c]
            take = 0
            if c >= (i + 1):
                take = prices[i] + dp[i][c - (i + 1)]
            dp[i][c] = max(take, notTake)

    return dp[n - 1][n]
