def fun(arr):
    n = len(arr)
    dp = [-1] * n

    def recur(i):
        if i == 0:
            return arr[i]

        if i < 0:
            return 0

        if dp[i] != -1:
            return dp[i]

        left = recur(i - 2) + arr[i]
        right = recur(i - 1)

        dp[i] = max(left, right)
        return dp[i]

    return recur(n - 1)


def optimal(arr):
    return max(fun(arr[1:]), fun(arr[:-1]))
