def optimal(arr, target):
    ans = []
    ds = []

    arr.sort()

    def recur(index, k):
        if k == 0:
            ans.append(ds[:])
            return

        for i in range(index, len(arr)):
            if i > index and arr[i] == arr[i - 1]:
                continue
            if arr[i] > k:
                return
            ds.append(arr[i])
            recur(i + 1, k - arr[i])
            ds.pop()

    recur(0, target)
    return ans


print(optimal([10, 1, 2, 7, 6, 1, 5], 8))
