## Only works for 1 common string ##


def tab(s1, s2):
    n = len(s1)
    m = len(s2)

    dp = [[0] * (m + 1) for _ in range(n + 1)]

    for i in range(n + 1):
        dp[i][0] = 0

    for j in range(m + 1):
        dp[0][j] = 0

    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if s1[i - 1] == s2[j - 1]:
                dp[i][j] = 1 + dp[i - 1][j - 1]
            else:
                one = dp[i - 1][j]
                two = dp[i][j - 1]
                dp[i][j] = max(one, two)

    i = n
    j = m
    index = dp[n][m] - 1

    ans = [""] * dp[n][m]

    while i > 0 and j > 0:
        if s1[i - 1] != s2[j - 1]:
            if dp[i - 1][j] > dp[i][j - 1]:
                i = i - 1
            elif dp[i][j - 1] > dp[i - 1][j]:
                j = j - 1
        else:
            ans[index] = s1[i - 1]
            i = i - 1
            j = j - 1
            index -= 1
    return "".join(ans)


s1 = "abcde"
s2 = "bdgek"

print(tab(s1, s2))
