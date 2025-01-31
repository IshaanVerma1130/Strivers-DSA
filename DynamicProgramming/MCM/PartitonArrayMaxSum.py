def recur(arr, k):
    n = len(arr)

    dp = [-1] * n

    def recur(i):
        if i == n:
            return 0

        if dp[i] != -1:
            return dp[i]

        length = 0
        maxi = 0
        maxS = 0
        for j in range(i, min(n, i + k)):
            maxi = max(maxi, arr[j])
            length += 1
            s = length * maxi + recur(j + 1)
            maxS = max(maxS, s)

        dp[i] = maxS
        return maxS

    return recur(0)
