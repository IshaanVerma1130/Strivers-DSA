def fun(s1, s2):
    n = len(s1)
    m = len(s2)

    dp = [[-1] * m for _ in range(n)]

    def recur(i, j):
        if i < 0:
            if j < 0:
                return True
            if j >= 0:
                return False

        if j < 0:
            if i >= 0:
                for it in range(i + 1):
                    if s1[it] != "*":
                        return False
                return True

        if dp[i][j] != -1:
            return dp[i][j]

        if s1[i] == s2[j] or s1[i] == "?":
            dp[i][j] = recur(i - 1, j - 1)
            return dp[i][j]

        if s1[i] == "*":
            dontMatchStar = recur(i - 1, j)
            matchStar = recur(i, j - 1)
            dp[i][j] = matchStar or dontMatchStar
            return matchStar or dontMatchStar

        dp[i][j] = False
        return False

    return recur(n - 1, m - 1)


print(fun("c*a*b", "aab"))
