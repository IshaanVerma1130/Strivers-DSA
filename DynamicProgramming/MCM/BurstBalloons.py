def fun(arr):
    n = len(arr)
    arr.insert(0, 1)
    arr.append(1)

    dp = [[-1] * (n + 1) for _ in range(n + 1)]

    def recur(i, j):
        if i > j:
            return 0
        if dp[i][j] != -1:
            return dp[i][j]
        maxi = 0
        for k in range(i, j + 1):
            cost = arr[i - 1] * arr[k] * arr[j + 1] + recur(i, k - 1) + recur(k + 1, j)
            maxi = max(maxi, cost)
        dp[i][j] = maxi
        return maxi

    return recur(1, n)


def tab(arr):
    n = len(arr)
    arr.insert(0, 1)
    arr.append(1)

    dp = [[0] * (n + 2) for _ in range(n + 2)]

    for i in range(n, 0, -1):
        for j in range(i, n + 1):
            maxi = -1
            for k in range(i, j + 1):
                cost = arr[i - 1] * arr[k] * arr[j + 1] + dp[i][k - 1] + dp[k + 1][j]
                maxi = max(maxi, cost)
            dp[i][j] = maxi

    return dp[1][n]
