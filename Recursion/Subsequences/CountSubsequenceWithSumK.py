def recur(index: int, arr: list[int], targetSum: int, sum: int):
    if index == len(arr):
        if sum == targetSum:
            return 1
        return 0

    left = recur(index + 1, arr, targetSum, sum + arr[index])
    right = recur(index + 1, arr, targetSum, sum)

    return left + right


def optimal(arr, k):
    sum = 0
    index = 0

    print(recur(index, arr, k, sum))


optimal([17, 18, 6, 11, 2, 4], 6)
