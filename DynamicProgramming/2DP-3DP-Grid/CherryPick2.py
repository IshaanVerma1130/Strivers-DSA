def optimal(grid):
    n = len(grid)
    m = len(grid[0])

    dp = [[[-1] * m for j in range(m)] for i in range(n)]

    def recur(i, aj, bj):
        if aj < 0 or bj < 0 or aj >= m or bj >= m:
            return -1e9

        if i == n - 1:
            if aj == bj:
                return grid[i][aj]
            else:
                return grid[i][aj] + grid[i][bj]

        if dp[i][aj][bj] != -1:
            return dp[i][aj][bj]

        maxi = 0
        for ac in [-1, 0, 1]:
            for bc in [-1, 0, 1]:
                if aj == bj:
                    maxi = max(maxi, grid[i][aj] + recur(i + 1, aj + ac, bj + bc))
                else:
                    maxi = max(
                        maxi, grid[i][aj] + grid[i][bj] + recur(i + 1, aj + ac, bj + bc)
                    )
        dp[i][aj][bj] = maxi
        return maxi

    return recur(0, 0, 0, m - 1)
