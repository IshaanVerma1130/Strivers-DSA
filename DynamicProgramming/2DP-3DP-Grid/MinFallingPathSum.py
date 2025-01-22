def optimal(matrix, j):
    n = len(matrix)
    m = len(matrix[0])

    dp = [[-1] * m for _ in range(n)]

    def recur(row, col):
        if row >= n or col >= m or col < 0:
            return 10000000

        if row == n - 1:
            return matrix[row][col]

        if dp[row][col] != -1:
            return dp[row][col]

        down = matrix[row][col] + recur(row + 1, col)
        diagonalRight = matrix[row][col] + recur(row + 1, col + 1)
        diagonalLeft = matrix[row][col] + recur(row + 1, col - 1)

        dp[row][col] = min(diagonalLeft, min(down, diagonalRight))

        return dp[row][col]

    return recur(0, j)


def helper(matrix):
    ans = 1e9

    for j in range(len(matrix[0])):
        ans = min(ans, optimal(matrix, j))

    return ans


def tabulation(matrix):
    n = len(matrix)
    m = len(matrix[0])

    dp = [[1e9] * (m) for _ in range(n)]

    for i in range(m):
        dp[0][i] = matrix[0][i]

    for i in range(1, n):
        for j in range(0, m):
            up = matrix[i][j] + dp[i - 1][j]
            diagonalRight = 1e9
            diagonalLeft = 1e9
            if j + 1 < n:
                diagonalRight = matrix[i][j] + dp[i - 1][j + 1]
            if j - 1 >= 0:
                diagonalLeft = matrix[i][j] + dp[i - 1][j - 1]

            dp[i][j] = min(diagonalLeft, min(up, diagonalRight))

    mini = 1e9

    for i in range(m):
        mini = min(mini, dp[n - 1][i])

    return mini
