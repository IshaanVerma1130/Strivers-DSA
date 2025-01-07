def memoiaztion(n):
    dp = [-1] * (n + 1)

    def recur(i):
        if i <= 1:
            return i

        if dp[i] != -1:
            return dp[i]

        dp[i] = recur(i - 1) + recur(i - 2)

        return dp[i]

    recur(n)
    return dp[n]


def tabulation(n):
    dp = [-1] * (n + 1)
    dp[0], dp[1] = 0, 1

    for i in range(2, n + 1):
        dp[i] = dp[i - 1] + dp[i - 2]

    return dp[n]


def optimal(n):
    if n <= 1:
        return 0

    prev = 1
    prev_prev = 0

    for i in range(2, n + 1):
        cur = prev + prev_prev
        prev_prev = prev
        prev = cur

    return prev


print(memoiaztion(10))  # 55
print(tabulation(10))  # 55
print(optimal(10))  # 55
