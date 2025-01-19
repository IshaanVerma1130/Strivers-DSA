def optimal(height):
    n = len(height)
    dp = [-1] * (n + 1)

    def recur(i):
        if i == 0:
            return 0

        if dp[i] != -1:
            return dp[i]

        left = recur(i - 1) + abs(height[i] - height[i - 1])
        right = 10001
        if i > 1:
            right = recur(i - 2) + abs(height[i] - height[i - 2])
        dp[i] = min(left, right)
        return dp[i]

    return recur(n - 1)


def dynPro(height):
    n = len(height)
    dp = [-1] * n
    dp[0] = 0

    for i in range(1, n):
        left = dp[i - 1] + abs(height[i] - height[i - 1])
        right = 10001

        if i > 1:
            right = dp[i - 2] + abs(height[i] - height[i - 2])
        dp[i] = min(left, right)

    return dp[n - 1]
