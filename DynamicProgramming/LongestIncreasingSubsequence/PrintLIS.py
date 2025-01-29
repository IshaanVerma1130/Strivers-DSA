def fun(arr):
    n = len(arr)
    dp = [1] * (n)
    hsh = [i for i in range(n)]

    maxi = 1
    lastIndex = 0

    for i in range(n):
        for j in range(i):
            if arr[i] > arr[j]:
                if dp[j] + 1 > dp[i]:
                    dp[i] = dp[j] + 1
                    hsh[i] = j
        if dp[i] > maxi:
            maxi = dp[i]
            lastIndex = i

    lis = [0] * maxi
    index = maxi - 1
    while lastIndex != hsh[lastIndex]:
        lis[index] = arr[lastIndex]
        lastIndex = hsh[lastIndex]
        index -= 1
    lis[index] = arr[lastIndex]

    return lis
