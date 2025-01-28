def tab(arr, k):
    n = len(arr)

    dp = [[[0] * (k + 1) for _ in range(2)] for _ in range(n + 1)]

    for i in range(n - 1, -1, -1):
        for buy in range(2):
            for txn in range(1, k + 1):
                maxProfit = 0
                if buy == 1:
                    take = -arr[i] + dp[i + 1][0][txn]
                    notTake = dp[i + 1][1][txn]
                    maxProfit = max(take, notTake)

                elif buy == 0:
                    take = arr[i] + dp[i + 1][1][txn - 1]
                    notTake = dp[i + 1][0][txn]
                    maxProfit = max(take, notTake)

                dp[i][buy][txn] = maxProfit

    return dp[0][1][k]
