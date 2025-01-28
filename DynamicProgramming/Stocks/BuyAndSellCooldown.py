def fun(arr):
    n = len(arr)

    dp = [[-1] * 2 for _ in range(n)]

    def recur(i, buy):
        if i >= n:
            return 0

        if dp[i][buy] != -1:
            return dp[i][buy]

        maxProfit = 0
        if buy == 1:
            take = -arr[i] + recur(i + 1, 0)
            notTake = recur(i + 1, 1)
            maxProfit = max(take, notTake)

        elif buy == 0:
            take = arr[i] + recur(i + 2, 1)
            notTake = recur(i + 1, 0)
            maxProfit = max(take, notTake)

        dp[i][buy] = maxProfit
        return maxProfit

    return recur(0, 1)


def tab(arr):
    n = len(arr)

    dp = [[0] * 2 for i in range(n + 2)]

    for buy in range(2):
        dp[n][buy] = 0

    for i in range(n - 1, -1, -1):
        for buy in range(2):
            maxProfit = 0
            if buy == 1:
                take = -arr[i] + dp[i + 1][0]
                notTake = dp[i + 1][1]
                maxProfit = max(take, notTake)

            elif buy == 0:
                take = arr[i] + dp[i + 1][1]
                notTake = dp[i + 1][0]
                maxProfit = max(take, notTake)

            dp[i][buy] = maxProfit

    return dp[0][1]
