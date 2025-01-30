def optimal(arr, diff):
    s = sum(arr)
    t = (s - diff) // 2  # s2

    if (s - diff) % 2 != 0 or (s - diff) < 0:
        return 0

    dp = [[-1] * (t + 1) for _ in range(len(arr))]

    def recur(i, target):
        if i < 0:
            return target == 0

        if dp[i][target] != -1:
            return dp[i][target]

        notTake = recur(i - 1, target)
        take = 0
        if target >= arr[i]:
            take = recur(i - 1, target - arr[i])

        dp[i][target] = take + notTake

        return take + notTake

    return recur(len(arr) - 1, t)
