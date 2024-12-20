def optimal(k, n):
    ds = []
    ans = []

    def arrSum(arr: list[int]):
        return sum(arr)

    def recur(k, num):
        if k == 0:
            if arrSum(ds) == n:
                ans.append(ds[:])
            return
        if num > 9:
            return
        ds.append(num)
        recur(k - 1, num + 1)
        ds.pop()
        recur(k, num + 1)

    recur(k, 1)
    return ans


print(optimal(3, 7))  # [[1, 2, 4]]
