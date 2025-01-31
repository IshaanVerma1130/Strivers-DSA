def fun(arr: list, length):
    n = len(arr)

    arr.insert(0, 0)
    arr.append(length)
    arr.sort()

    dp = [[-1] * (n + 1) for _ in range(n + 1)]

    def recur(i, j):
        if i > j:
            return 0
        if dp[i][j] != -1:
            return dp[i][j]
        mini = 10**9
        for k in range(i, j + 1):
            profit = arr[j + 1] - arr[i - 1] + recur(i, k - 1) + recur(k + 1, j)
            mini = min(mini, profit)
        dp[i][j] = mini
        return mini

    return recur(1, n)


def tab(arr: list, length):
    n = len(arr)

    arr.insert(0, 0)
    arr.append(length)
    arr.sort()

    dp = [[0] * (n + 2) for _ in range(n + 2)]

    for i in range(n, 0, -1):
        for j in range(i, n + 1):
            mini = 10**9
            for k in range(i, j + 1):
                profit = arr[j + 1] - arr[i - 1] + dp[i][k - 1] + dp[k + 1][j]
                mini = min(mini, profit)
            dp[i][j] = mini

    return dp[1][n]
