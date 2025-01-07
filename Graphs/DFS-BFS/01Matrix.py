def optimal(grid):
    n, m = len(grid), len(grid[0])
    q = []
    vis = [[0] * m for _ in range(n)]
    ans = [[0] * m for _ in range(n)]

    for i in range(n):
        for j in range(m):
            if grid[i][j] == 0:
                vis[i][j] = 1
                q.append((i, j, 0))

    while q:
        row, col, dis = q.pop(0)
        ans[row][col] = dis

        for i, j in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
            newRow, newCol = row + i, col + j
            if (
                newRow >= 0
                and newRow < n
                and newCol >= 0
                and newCol < m
                and not vis[newRow][newCol]
            ):
                vis[newRow][newCol] = 1
                q.append((newRow, newCol, dis + 1))

    return ans


ans = optimal([[0, 0, 0], [0, 1, 0], [0, 0, 0]])

for i in ans:
    print(i)
