def fun(arr):
    n = len(arr)
    dp = [[-1] * n for _ in range(n)]

    def recur(i, j):
        if i == j:
            return 0
        if dp[i][j] != -1:
            return dp[i][j]
        mini = 10**9
        for k in range(i, j):
            ops = arr[i - 1] * arr[k] * arr[j] + recur(i, k) + recur(k + 1, j)
            mini = min(mini, ops)
        dp[i][j] = mini
        return mini

    return recur(1, n - 1)


def tab(arr):
    n = len(arr)
    dp = [[10**9] * n for _ in range(n)]

    for i in range(n):
        dp[i][i] = 0

    for i in range(n - 1, 0, -1):
        for j in range(i + 1, n):
            mini = 10**9
            for k in range(i, j):
                ops = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j]
                mini = min(mini, ops)
            dp[i][j] = mini

    return dp[1][n - 1]
