def optimal(arr: list[int], k: int):
    ans = []
    ds = []

    def recur(index, target):
        if len(arr) == index:
            if target == 0:
                ans.append(ds[:])
            return

        if arr[index] <= target:
            ds.append(arr[index])
            recur(index, target - arr[index])
            ds.pop()

        recur(index + 1, target)

    recur(0, k)
    return ans


print(optimal([2, 3, 6, 7], 7))
