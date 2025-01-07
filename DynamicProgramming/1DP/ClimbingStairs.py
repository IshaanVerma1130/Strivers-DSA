def optimal(n):
    dp = [-1] * (n + 1)

    def recur(n):
        if n == 0:
            return 1

        if n < 0:
            return 0

        if dp[n] != -1:
            return dp[n]

        dp[n] = recur(n - 1) + recur(n - 2)
        return dp[n]

    return recur(n)


print(optimal(38))
