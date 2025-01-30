def optimal(arr, target):
    n = len(arr)

    dp = [[-1] * (target + 1) for _ in range(n)]

    def recur(i, t):
        if i < 0:
            return 1 if t == 0 else 0

        if dp[i][t] != -1:
            return dp[i][t]

        notTake = recur(i - 1, t)
        take = 0
        if t >= arr[i]:
            take = recur(i - 1, t - arr[i])
        dp[i][t] = notTake + take
        return notTake + take

    return recur(n - 1, target)


print(optimal([28, 4, 3, 27, 0, 24, 26], 24))
