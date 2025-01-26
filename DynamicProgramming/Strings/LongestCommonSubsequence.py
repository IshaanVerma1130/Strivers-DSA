# Without index shifting
def fun(s1, s2):
    n = len(s1)
    m = len(s2)

    dp = [[-1] * m for _ in range(n)]

    def recur(i, j):
        if i < 0 or j < 0:
            return 0

        if dp[i][j] != -1:
            return dp[i][j]

        if s1[i] == s2[j]:
            return 1 + recur(i - 1, j - 1)

        one = recur(i - 1, j)
        two = recur(i, j - 1)

        dp[i][j] = max(one, two)

        return max(one, two)

    return recur(n - 1, m - 1)


# With index shifting
# n = len(s1)
# m = len(s2)

# dp = [[-1] * (m+1) for _ in range(n+1)]

# def recur(i, j):
#     if i == 0 or j == 0:
#         return 0

#     if s1[i-1] == s2[j-1]:
#         return 1 + recur(i - 1, j - 1)

#     if dp[i][j] != -1:
#         return dp[i][j]

#     one = recur(i - 1, j)
#     two = recur(i, j - 1)

#     dp[i][j] = max(one, two)

#     return max(one, two)

# return recur(n, m)


def tab(s1, s2):
    n = len(s1)
    m = len(s2)

    dp = [[0] * (m + 1) for _ in range(n + 1)]

    for i in range(n + 1):
        dp[i][0] = 0

    for j in range(m + 1):
        dp[0][j] = 0

    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if s1[i - 1] == s2[j - 1]:
                dp[i][j] = 1 + dp[i - 1][j - 1]
            else:
                one = dp[i - 1][j]
                two = dp[i][j - 1]
                dp[i][j] = max(one, two)

    return dp[n][m]
