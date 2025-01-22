def optimal(grid):
    n = len(grid)
    m = len(grid[0])

    dp = [[-1] * m for _ in range(n)]

    def recur(row, col):
        if row == n - 1 and col == m - 1:
            return grid[row][col]

        if row < 0 or col < 0 or row >= n or col >= m:
            return 10000000

        if dp[row][col] != -1:
            return dp[row][col]

        down = recur(row + 1, col) + grid[row][col]
        right = recur(row, col + 1) + grid[row][col]

        dp[row][col] = min(down, right)

        return dp[row][col]

    return recur(0, 0)


print(optimal([[1, 3, 1], [1, 5, 1], [4, 2, 1]]))
