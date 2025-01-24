def optimal(arr):
    n = len(arr)

    s = sum(arr)

    dp = [[False] * (s + 1) for _ in range(n)]

    for i in range(n):
        dp[i][0] = True

    dp[0][arr[0]] = True

    for i in range(1, n):
        for t in range(s + 1):
            notTake = dp[i - 1][t]
            take = False
            if t >= arr[i]:
                take = dp[i - 1][t - arr[i]]
            dp[i][t] = take or notTake

    mini = 1e9
    for left in range(s // 2 + 1):
        if dp[n - 1][left] == True:
            right = s - left
            mini = min(mini, abs(left - right))

    return mini
