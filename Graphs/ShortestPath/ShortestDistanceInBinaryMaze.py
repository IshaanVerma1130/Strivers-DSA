def optimal(mat):
    n = len(mat)
    m = len(mat[0])

    if mat[0][0] == 1 or mat[n - 1][m - 1] == 1:
        return -1

    dis = [[float("inf")] * m for _ in range(n)]
    dis[0][0] = 0

    q = []
    q.append((1, 0, 0))

    while q:
        d, i, j = q.pop(0)

        if i == n - 1 and j == m - 1:
            return d

        for x in [-1, 0, 1]:
            for y in [-1, 0, 1]:
                newR = i + x
                newC = j + y

                if (
                    newR < n
                    and newC < m
                    and newR >= 0
                    and newC >= 0
                    and d + 1 < dis[newR][newC]
                    and mat[newR][newC] == 0
                ):
                    dis[newR][newC] = d + 1
                    q.append((d + 1, newR, newC))

    return -1


print(optimal([[0]]))
