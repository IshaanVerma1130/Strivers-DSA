def fun(arr):
    n = len(arr)
    dp = [1] * n
    count = [1] * n
    maxi = 1

    # arr= 1, 3, 5, 4, 7
    # dp=  1, 2, 3, 3, 4
    # cnt= 1, 1, 1, 1, 2
    for i in range(n):
        for j in range(i):
            if arr[i] > arr[j]:
                if dp[i] < dp[j] + 1:
                    dp[i] = dp[j] + 1
                    maxi = max(maxi, dp[i])
                    count[i] = count[j]
                elif dp[i] == dp[j] + 1:
                    count[i] += count[j]

    maxCount = 0

    for i in range(n):
        if dp[i] == maxi:
            maxCount += count[i]

    return maxCount
