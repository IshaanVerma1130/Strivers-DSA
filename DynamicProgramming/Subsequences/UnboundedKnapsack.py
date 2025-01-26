def fun(capacity, val, wt):
    n = len(val)

    dp = [[-1] * (capacity + 1) for _ in range(n)]

    def recur(i, cap):
        if i == 0:
            if wt[0] <= cap:
                return (cap // wt[0]) * val[0]
            else:
                return 0

        if dp[i][cap] != -1:
            return dp[i][cap]

        notTake = recur(i - 1, cap)
        take = 0
        if wt[i] <= cap:
            take = recur(i, cap - wt[i]) + val[i]
        dp[i][cap] = max(take, notTake)
        return max(take, notTake)

    return recur(n - 1, capacity)


def tab(capacity, val, wt):
    n = len(val)

    dp = [[0] * (capacity + 1) for _ in range(n)]

    for cap in range(capacity + 1):
        if wt[0] <= cap:
            dp[0][cap] = (cap // wt[0]) * val[0]

    for i in range(1, n):
        for cap in range(capacity + 1):
            notTake = dp[i - 1][cap]
            take = 0
            if wt[i] <= cap:
                take = dp[i][cap - wt[i]] + val[i]
            dp[i][cap] = max(take, notTake)

    return dp[n - 1][capacity]
