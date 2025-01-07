def optimal(grid):
    n, m = len(grid), len(grid[0])
    vis = [[0] * m for _ in range(n)]

    def dfs(row, col):
        vis[row][col] = 1

        for i, j in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
            newRow, newCol = row + i, col + j

            if (
                newCol < m
                and newRow < n
                and newCol >= 0
                and newRow >= 0
                and vis[newRow][newCol] == 0
                and grid[newRow][newCol] == "O"
            ):
                dfs(newRow, newCol)

    for i in range(n):
        if grid[i][0] == "O" and vis[i][0] == 0:
            dfs(i, 0)
        if grid[i][m - 1] == "O" and vis[i][m - 1] == 0:
            dfs(i, m - 1)

    for j in range(m):
        if grid[0][j] == "O" and vis[0][j] == 0:
            dfs(0, j)
        if grid[n - 1][j] == "O" and vis[n - 1][j] == 0:
            dfs(n - 1, j)

    for i in range(n):
        for j in range(m):
            if grid[i][j] == "O" and vis[i][j] == 0:
                grid[i][j] = "X"
