def optimal(triangle):
    n = len(triangle)

    dp = []

    for i in range(n):
        dp.append([-1] * (len(triangle[i])))

    def recur(row, col):
        if row == n - 1:
            return triangle[row][col]

        if row >= n or col >= len(triangle[row]):
            return 10000000

        if dp[row][col] != -1:
            return dp[row][col]

        down = triangle[row][col] + recur(row + 1, col)
        diagonal = triangle[row][col] + recur(row + 1, col + 1)

        dp[row][col] = min(down, diagonal)

        return dp[row][col]

    return recur(0, 0)
