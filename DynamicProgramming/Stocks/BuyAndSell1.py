def fun(arr):
    n = len(arr)

    mini = arr[0]
    maxi = -1

    for curr in arr:
        maxi = max(maxi, curr - mini)
        mini = min(mini, curr)

    return maxi


print(fun())
