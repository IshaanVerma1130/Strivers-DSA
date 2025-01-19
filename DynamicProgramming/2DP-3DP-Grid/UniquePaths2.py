def optimal(obstacle):
    n = len(obstacle)
    m = len(obstacle[0])

    if obstacle[0][0] == 1 or obstacle[n - 1][m - 1] == 1:
        return 0

    dp = [[-1] * m for _ in range(n)]

    def recur(i, j):
        if i == n - 1 and j == m - 1:
            return 1

        if i >= n or j >= m:
            return 0

        if obstacle[i][j] == 1:
            return 0

        if dp[i][j] != -1:
            return dp[i][j]

        left = recur(i + 1, j)
        right = recur(i, j + 1)

        dp[i][j] = left + right
        return left + right

    return recur(0, 0)
