def fun(arr):
    n = len(arr)
    dp1 = [1] * n
    dp2 = [1] * n

    for i in range(n):
        for j in range(i):
            if arr[i] > arr[j]:
                dp1[i] = max(dp1[i], dp1[j] + 1)

    for i in range(n - 1, -1, -1):
        for j in range(n - 1, i, -1):
            if arr[i] > arr[j]:
                dp2[i] = max(dp2[i], dp2[j] + 1)

    maxi = 0

    for i in range(n):
        if dp1[i] > 1 and dp2[i] > 1:
            maxi = max(maxi, dp1[i] + dp2[i] - 1)
    print(dp1)
    print(dp2)

    return maxi


print(fun([1, 4, 2, 7, 9, 10]))
