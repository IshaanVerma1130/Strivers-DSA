from heapq import heappop, heappush


def optimal(mat):
    n = len(mat)
    m = len(mat[0])

    dis = [[float("inf")] * m for _ in range(n)]
    dis[0][0] = 0

    q = []
    heappush(q, (0, 0, 0))

    while q:
        d, i, j = heappop(q)

        if i == n - 1 and j == m - 1:
            return d

        for x, y in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            newR = i + x
            newC = j + y

            if newR < n and newC < m and newR >= 0 and newC >= 0:
                newEff = max(abs(mat[i][j] - mat[newR][newC]), d)
                if newEff < dis[newR][newC]:
                    dis[newR][newC] = newEff
                    heappush(q, (newEff, newR, newC))
