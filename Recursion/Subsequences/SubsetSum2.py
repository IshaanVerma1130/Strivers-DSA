def optimal(arr):
    ans = []
    ds = []
    arr.sort()

    def recur(index):
        ans.append(ds[:])

        for i in range(index, len(arr)):
            if i > index and arr[i] == arr[i - 1]:
                continue
            ds.append(arr[i])
            recur(i + 1)
            ds.pop()

    recur(0)
    return ans


print(optimal([1, 2, 2]))
