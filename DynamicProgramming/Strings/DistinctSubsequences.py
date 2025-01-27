def fun(s1, s2):
    n = len(s1)
    m = len(s2)

    dp = [[-1] * (m) for _ in range(n)]

    def recur(i, j):
        if j < 0:
            return 1

        if i < 0:
            return 0

        if dp[i][j] != -1:
            return dp[i][j]

        if s1[i] == s2[j]:
            take = recur(i - 1, j - 1)
            notTake = recur(i - 1, j)
            dp[i][j] = take + notTake
            return take + notTake

        notTake = recur(i - 1, j)
        dp[i][j] = notTake
        return notTake

    return recur(n - 1, m - 1)


def tab(s1, s2):
    n = len(s1)
    m = len(s2)

    dp = [[0] * (m + 1) for _ in range(n + 1)]

    for i in range(n + 1):
        dp[i][0] = 1

    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if s1[i - 1] == s2[j - 1]:
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]
            else:
                dp[i][j] = dp[i - 1][j]

    return dp[n][m]


def op(s1, s2):
    n = len(s1)
    m = len(s2)

    prev = [0] * (m + 1)
    cur = [0] * (m + 1)

    prev[0] = 1
    cur[0] = 1
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if s1[i - 1] == s2[j - 1]:
                cur[j] = prev[j - 1] + prev[j]
            else:
                cur[j] = prev[j]
        prev = cur[:]

    return prev[m]


print(op("rabbbit", "rabbit"))
