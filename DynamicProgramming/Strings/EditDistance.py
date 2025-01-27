def fun(s1, s2):
    n = len(s1)
    m = len(s2)

    dp = [[-1] * m for _ in range(n)]

    def recur(i, j):
        if j < 0:
            return i + 1

        if i < 0:
            return j + 1

        if dp[i][j] != -1:
            return dp[i][j]

        if s1[i] == s2[j]:
            return recur(i - 1, j - 1)

        insert = 1 + recur(i - 1, j)
        delete = 1 + recur(i, j - 1)
        replace = 1 + recur(i - 1, j - 1)

        dp[i][j] = min(insert, min(delete, replace))

        return min(insert, min(delete, replace))

    return recur(n - 1, m - 1)


def tab(s1, s2):
    n = len(s1)
    m = len(s2)

    dp = [[n + m] * (m + 1) for _ in range(n + 1)]

    for i in range(n + 1):
        dp[i][0] = i

    for j in range(m + 1):
        dp[0][j] = j

    for i in range(1, n + 1):
        for j in range(m + 1):
            if s1[i - 1] == s2[j - 1]:
                dp[i][j] = dp[i - 1][j - 1]
            else:
                insert = 1 + dp[i - 1][j]
                delete = 1 + dp[i][j - 1]
                replace = 1 + dp[i - 1][j - 1]

                dp[i][j] = min(insert, min(delete, replace))

    return dp[n][m]
