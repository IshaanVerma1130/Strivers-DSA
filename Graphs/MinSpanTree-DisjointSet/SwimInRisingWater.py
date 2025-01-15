from heapq import heappop, heappush


def optimal(mat):
    n = len(mat)
    m = len(mat[0])

    vis = [[0] * m for _ in range(n)]
    vis[0][0] = 1
    # (time, i, j)
    q = [(mat[0][0], 0, 0)]

    while q:
        time, row, col = heappop(q)

        if row == n - 1 and col == m - 1:
            return time

        for i, j in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
            newR = row + i
            newC = col + j

            if (
                newR < n
                and newC < m
                and newR >= 0
                and newC >= 0
                and vis[newR][newC] == 0
            ):
                vis[newR][newC] = 1
                if mat[newR][newC] <= time:
                    heappush(q, (time, newR, newC))

                else:
                    heappush(q, (mat[newR][newC], newR, newC))


print(optimal([[3, 2], [0, 1]]))
