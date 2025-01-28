def fun(arr):
    n = len(arr)

    dp = [[[-1, -1, -1] for _ in range(2)] for _ in range(n)]

    def recur(i, buy, txn):
        if txn == 0:
            return 0

        if i == n:
            return 0

        if dp[i][buy][txn] != -1:
            return dp[i][buy][txn]

        maxProfit = 0
        if buy == 1:
            take = -arr[i] + recur(i + 1, 0, txn)
            notTake = recur(i + 1, 1, txn)
            maxProfit = max(take, notTake)

        elif buy == 0:
            take = arr[i] + recur(i + 1, 1, txn - 1)
            notTake = recur(i + 1, 0, txn)
            maxProfit = max(take, notTake)

        dp[i][buy][txn] = maxProfit
        return maxProfit

    return recur(0, 1, 2)


def tab(arr):
    n = len(arr)

    dp = [[[0, 0, 0] for _ in range(2)] for _ in range(n + 1)]

    for i in range(n - 1, -1, -1):
        for buy in range(2):
            for txn in range(1, 3):
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

    return dp[0][1][2]
