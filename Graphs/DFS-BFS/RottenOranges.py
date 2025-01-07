def optimal(grid):
    n = len(grid)
    m = len(grid[0])

    vis = [[0] * m for _ in range(n)]
    q = []
    time = 0
    for i in range(n):
        for j in range(m):
            if grid[i][j] == 2:
                q.append(((i, j), time))
                vis[i][j] = 1

    while q:
        (row, col), t = q.pop(0)
        time = max(time, t)
        dr = [-1, 1, 0, 0]
        dc = [0, 0, -1, 1]

        for i in range(4):
            r = row + dr[i]
            c = col + dc[i]

            if r < 0 or c < 0 or r >= n or c >= m:
                continue

            if vis[r][c] == 1 or grid[r][c] == 0:
                continue

            vis[r][c] = 1
            q.append(((r, c), t + 1))

    for i in range(n):
        for j in range(m):
            if grid[i][j] == 1 and vis[i][j] == 0:
                return -1

    return time


grid = [[2, 1, 1], [1, 1, 0], [0, 1, 1]]
print(optimal(grid))
