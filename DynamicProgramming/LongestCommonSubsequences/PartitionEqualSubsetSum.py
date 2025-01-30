def optimal(arr):
    s = sum(arr)

    if s % 2 != 0:
        return False

    n = len(arr)

    dp = [[-1] * s for _ in range(n)]

    def recur(i, target):
        if target == 0:
            return True

        if i == 0:
            return target == arr[0]

        if dp[i][target] != -1:
            return dp[i][target]

        notTake = recur(i - 1, target)
        take = False

        if target >= arr[i]:
            take = recur(i - 1, target - arr[i])

        dp[i][target] = take or notTake

        return take or notTake

    return recur(n - 1, s // 2)
