def fun(coins, amount):
    n = len(coins)

    dp = [[-1] * (amount + 1) for _ in range(n)]

    def recur(i, amt):
        if i == 0:
            if amt % coins[i] == 0:
                return 1
            else:
                return 0

        if dp[i][amt] != -1:
            return dp[i][amt]

        notTake = recur(i - 1, amt)
        take = 0
        if coins[i] <= amt:
            take = recur(i, amt - coins[i])
        dp[i][amt] = take + notTake
        return notTake + take

    return recur(n - 1, amount)


def tab(coins, amount):
    n = len(coins)

    dp = [[0] * (amount + 1) for _ in range(n)]

    for amt in range(amount + 1):
        if amt % coins[0] == 0:
            dp[0][amt] = 1

    for i in range(1, n):
        for amt in range(amount + 1):
            notTake = dp[i - 1][amt]
            take = 0
            if amt >= coins[i]:
                take = dp[i][amt - coins[i]]
            dp[i][amt] = take + notTake

    return dp[n - 1][amount]
