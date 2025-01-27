def fun(str1, str2):
    n = len(str1)
    m = len(str2)

    dp = [[-1] * m for _ in range(n)]

    def recur(i, j):
        if i < 0 or j < 0:
            return 0

        if dp[i][j] != -1:
            return dp[i][j]

        if str1[i] == str2[j]:
            return 1 + recur(i - 1, j - 1)

        one = recur(i - 1, j)
        two = recur(i, j - 1)

        dp[i][j] = max(one, two)

        return max(one, two)

    return n + m - (2 * recur(n - 1, m - 1))
