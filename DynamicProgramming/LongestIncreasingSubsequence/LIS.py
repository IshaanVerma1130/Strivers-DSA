def fun(arr):
    n = len(arr)

    dp = [[-1] * (n + 1) for _ in range(n)]

    def recur(i, prev):
        if i == n:
            return 0

        if dp[i][prev + 1] != -1:
            return dp[i][prev + 1]

        notTake = recur(i + 1, prev)
        take = 0
        if prev == -1 or arr[i] > arr[prev]:
            take = 1 + recur(i + 1, i)

        dp[i][prev + 1] = max(take, notTake)
        return max(take, notTake)

    return recur(0, -1)


def tab(arr):
    n = len(arr)

    dp = [[0] * (n + 1) for _ in range(n + 1)]
    for i in range(n - 1, -1, -1):
        for prev in range(i - 1, -2, -1):
            notTake = dp[i + 1][prev + 1]
            take = 0
            if prev == -1 or arr[i] > arr[prev]:
                take = 1 + dp[i + 1][i + 1]

            dp[i][prev + 1] = max(take, notTake)

    return dp[0][0]


def lowerBound(arr, k):
    low = 0
    high = len(arr) - 1
    res = -1

    while low <= high:
        mid = low + (high - low) // 2
        if arr[mid] >= k:
            high = mid - 1
            res = mid
        else:
            low = mid + 1

    return res


def optimal(arr):
    temp = [arr[0]]

    for i in range(len(arr)):
        if arr[i] > temp[-1]:
            temp.append(arr[i])
        else:
            lb_index = lowerBound(temp, arr[i])
            temp[lb_index] = arr[i]

    return len(temp)
