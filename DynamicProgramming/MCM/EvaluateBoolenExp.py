def fun(exp):
    n = len(exp)

    dp = [[[-1, -1] for _ in range(n)] for _ in range(n)]

    def recur(i, j, isTrue):
        if i > j:
            return 0

        if i == j:
            if isTrue == 1:
                if exp[i] == "T":
                    return 1
                return 0
            if isTrue == 0:
                if exp[i] == "F":
                    return 1
                return 0

        if dp[i][j][isTrue] != -1:
            return dp[i][j][isTrue]

        ways = 0
        for k in range(i + 1, j, 2):
            lt = recur(i, k - 1, 1)
            lf = recur(i, k - 1, 0)
            rt = recur(k + 1, j, 1)
            rf = recur(k + 1, j, 0)

            if exp[k] == "&":
                if isTrue == 1:
                    ways += lt * rt
                elif isTrue == 0:
                    ways += lf * rf + lf * rt + lt * rf
            elif exp[k] == "|":
                if isTrue == 1:
                    ways += lt * rf + rt * lf + lt * rt
                elif isTrue == 0:
                    ways += lf * rf
            elif exp[k] == "^":
                if isTrue == 1:
                    ways += lt * rf + lf * rt
                elif isTrue == 0:
                    ways += lf * rf + lt * rt

        dp[i][j][isTrue] = ways
        return ways

    return recur(0, n - 1, 1)
