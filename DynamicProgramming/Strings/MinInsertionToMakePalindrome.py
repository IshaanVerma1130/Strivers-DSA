def fun(s):
    n = len(s)
    m = len(s)

    s1 = s
    s2 = s[::-1]

    dp = [[-1] * (m + 1) for _ in range(n + 1)]

    def recur(i, j):
        if i == 0 or j == 0:
            return 0

        if dp[i][j] != -1:
            return dp[i][j]

        if s1[i - 1] == s2[j - 1]:
            return 1 + recur(i - 1, j - 1)

        one = recur(i - 1, j)
        two = recur(i, j - 1)

        dp[i][j] = max(one, two)

        return max(one, two)

    return n - recur(n, m)
