# dfs
# def optimal(grid):
#     n, m = len(grid), len(grid[0])
#     vis = [[0] * m for _ in range(n)]

#     def dfs(row, col):
#         vis[row][col] = 1

#         for i, j in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
#             newRow, newCol = row + i, col + j

#             if (
#                 newCol < m
#                 and newRow < n
#                 and newCol >= 0
#                 and newRow >= 0
#                 and vis[newRow][newCol] == 0
#                 and grid[newRow][newCol] == 1
#             ):
#                 dfs(newRow, newCol)

#     for i in range(n):
#         if grid[i][0] == 1:
#             dfs(i, 0)
#         if grid[i][m - 1] == 1:
#             dfs(i, m - 1)

#     for j in range(m):
#         if grid[0][j] == 1:
#             dfs(0, j)
#         if grid[n - 1][j] == 1:
#             dfs(n - 1, j)

#     count = 0

#     for i in range(n):
#         for j in range(m):
#             if vis[i][j] == 0 and grid[i][j] == 1:
#                 count += 1

#     return count


# bfs
def optimal(grid):
    n, m = len(grid), len(grid[0])
    vis = [[0] * m for _ in range(n)]
    q = []

    for i in range(n):
        for j in range(m):
            if i == 0 or j == 0 or i == n - 1 or j == m - 1:
                if grid[i][j] == 1:
                    vis[i][j] = 1
                    q.append((i, j))

    while q:
        row, col = q.pop(0)

        for i, j in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
            newRow = row + i
            newCol = col + j

            if (
                newCol < m
                and newRow < n
                and newCol >= 0
                and newRow >= 0
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

    return count


print(optimal([[0, 0, 0, 0], [1, 0, 1, 0], [0, 1, 1, 0], [0, 0, 0, 0]]))
