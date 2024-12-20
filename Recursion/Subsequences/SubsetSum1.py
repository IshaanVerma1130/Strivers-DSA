def optimal(arr):
    ans = []

    def recur(index, sum):
        if index == len(arr):
            ans.append(sum)
            return

        recur(index + 1, sum + arr[index])
        recur(index + 1, sum)

    recur(0, 0)
    ans.sort()
    return ans


def brute(arr):
    ans = []


print(optimal([1, 2, 3]))
