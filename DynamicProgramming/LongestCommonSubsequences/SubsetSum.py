def optimal(arr, target):
    n = len(arr)

    dp = [[-1] * (target + 1) for _ in range(n)]

    def recur(i, t):
        if t == 0:
            return True

        if i == 0:
            return arr[0] == t

        if dp[i][t] != -1:
            return dp[i][t]

        notTake = recur(i - 1, t)
        take = False
        if t >= arr[i]:
            take = recur(i - 1, t - arr[i])
        dp[i][t] = take or notTake
        return take or notTake

    return recur(n - 1, target)


def tab(arr, target):
    n = len(arr)
    dp = [[False] * (target + 1) for _ in range(n)]

    for i in range(n):
        dp[i][0] = True

    if target >= arr[0]:
        dp[0][arr[0]] = True

    for i in range(1, n):
        for t in range(target + 1):
            notTake = dp[i - 1][t]
            take = False
            if t >= arr[i]:
                take = dp[i - 1][t - arr[i]]
            dp[i][t] = take or notTake

    return dp[n - 1][target]
