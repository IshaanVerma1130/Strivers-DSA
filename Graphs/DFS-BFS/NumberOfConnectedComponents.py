def optimal(grid):
    n = len(grid)
    m = len(grid[0])

    vis = [[0] * m for _ in range(n)]

    def bfs(row, col):
        q = [(row, col)]
        vis[row][col] = 1

        while q:
            r, c = q.pop(0)

            for i in [-1, 0, 1]:
                for j in [-1, 0, 1]:
                    newRow = r + i
                    newCol = c + j
                    if (
                        newRow >= 0
                        and newCol >= 0
                        and newCol < m
                        and newRow < n
                        and vis[newRow][newCol] == 0
                        and grid[newRow][newCol] == 1
                    ):
                        q.append((newRow, newCol))
                        vis[newRow][newCol] = 1

    count = 0

    for i in range(n):
        for j in range(m):
            if vis[i][j] == 0 and grid[i][j] == 1:
                count += 1
                bfs(i, j)

    return count


print(optimal([[1, 1, 0, 0, 0], [1, 0, 0, 0, 0], [0, 0, 0, 0, 1], [0, 0, 0, 1, 1]]))
