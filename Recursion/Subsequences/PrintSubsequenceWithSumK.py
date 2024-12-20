def recur(index: int, arr: list[int], targetSum: int, sum: int, ds: list[int]):
    if index == len(arr):
        if sum == targetSum:
            print(ds)
        return

    ds.append(arr[index])
    recur(index + 1, arr, targetSum, sum + arr[index], ds)
    ds.pop()
    recur(index + 1, arr, targetSum, sum, ds)


def optimal(arr, k):
    sum = 0
    ds = []
    index = 0

    recur(index, arr, k, sum, ds)


optimal([17, 18, 6, 11, 2, 4], 6)
