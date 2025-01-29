def fun(arr: list[str]):
    n = len(arr)
    arr.sort(key=len)

    dp = [1] * n

    maxi = 1

    def compare(s1, s2):
        i = 0
        j = 0

        n = len(s1)
        m = len(s2)

        if n != m + 1:
            return False

        while i < n:
            if j < m and s1[i] == s2[j]:
                i += 1
                j += 1
            else:
                i += 1

        if i == n and j == m:
            return True
        return False

    for i in range(n):
        for j in range(i):
            if compare(arr[i], arr[j]):
                if dp[i] < dp[j] + 1:
                    dp[i] = dp[j] + 1
        maxi = max(maxi, dp[i])

    return maxi


print(fun(["xbc", "pcxbcf", "xb", "cxbc", "pcxbc"]))
