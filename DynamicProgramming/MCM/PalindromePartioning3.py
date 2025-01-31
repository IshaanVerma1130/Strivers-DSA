def fun(s):
    n = len(s)

    dp = [-1] * n

    def isPalindrome(i, j):
        while i < j:
            if s[i] != s[j]:
                return False
            i += 1
            j -= 1

        return True

    def recur(i):
        if i == n:
            return 0

        if dp[i] != -1:
            return dp[i]

        mini = 10**9
        for k in range(i, n):
            if isPalindrome(i, k):
                cost = 1 + recur(k + 1)
                mini = min(cost, mini)

        dp[i] = mini
        return mini

    return recur(0) - 1


def tab(s):
    n = len(s)

    dp = [0] * (n + 1)

    palin = [[0] * n for _ in range(n)]

    def isPalindrome(i, j):
        while i < j:
            if s[i] != s[j]:
                return 0
            i += 1
            j -= 1

        return 1

    for i in range(n - 1, -1, -1):
        for j in range(i, n):
            palin[i][j] = isPalindrome(i, j)

    for i in range(n - 1, -1, -1):
        mini = 10**9
        for k in range(i, n):
            if palin[i][k] == 1:
                cost = 1 + dp[k + 1]
                mini = min(cost, mini)

        dp[i] = mini

    return dp[0] - 1
