def optimal(k, arr):
    n = len(arr)
    dp = [-1] * (n)
    dp[0] = 0

    for i in range(1, n):
        minSteps = 10001
        for j in range(1, k + 1):
            if i - j >= 0:
                jump = dp[i - j] + abs(arr[i] - arr[i - j])
                minSteps = min(minSteps, jump)
        dp[i] = minSteps

    return dp[n - 1]


print(optimal(3, [10, 30, 40, 50, 20]))
