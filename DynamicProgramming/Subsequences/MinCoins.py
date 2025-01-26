def optimal(coins, amt):
    n = len(coins)
    dp = [[-1] * (amt + 1) for _ in range(n)]

    def recur(i, amount):
        if amount == 0:
            return 0

        if i == 0:
            if amount % coins[0] == 0:
                return amount // coins[0]
            return 10**9

        if dp[i][amount] != -1:
            return dp[i][amount]

        notTake = 0 + recur(i - 1, amount)
        take = 10**9
        if coins[i] <= amount:
            take = 1 + recur(i, amount - coins[i])

        dp[i][amount] = min(take, notTake)

        return min(take, notTake)

    ans = recur(n - 1, amt)

    if ans >= 10**9:
        return -1
    return ans


def tab(coins, amount):
    n = len(coins)

    dp = [[10**9] * (amount + 1) for _ in range(n)]

    for i in range(n):
        dp[i][0] = 0

    for amt in range(0, amount + 1):
        if amt % coins[0] == 0:
            dp[0][amt] = amt // coins[0]
        else:
            dp[0][amt] = 10**9

    for i in range(1, n):
        for amt in range(amount + 1):
            notTake = dp[i - 1][amt]
            take = 10**9
            if coins[i] <= amt:
                take = 1 + dp[i][amt - coins[i]]
            dp[i][amt] = min(take, notTake)

    ans = dp[n - 1][amt]

    if ans >= 10**9:
        return -1
    return ans
