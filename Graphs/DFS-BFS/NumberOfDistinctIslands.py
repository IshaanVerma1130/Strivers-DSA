def optimal(grid):
    n = len(grid)
    m = len(grid[0])
    s = set()
    vis = [[0] * m for _ in range(n)]

    def dfs(row, col, baseRow, baseCol, vec):
        vis[row][col] = 1
        vec.append((row - baseRow, col - baseCol))

        for i, j in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            newRow = row + i
            newCol = col + j

            if (
                newRow >= 0
                and newCol >= 0
                and newRow < n
                and newCol < m
                and vis[newRow][newCol] == 0
                and grid[newRow][newCol] == 1
            ):
                dfs(newRow, newCol, baseRow, baseCol)

    for i in range(n):
        for j in range(m):
            if vis[i][j] == 0 and grid[i][j] == 1:
                vec = []
                dfs(i, j, i, j, vec)
                s.add(tuple(vec[:]))

    return len(s)


print(optimal())
