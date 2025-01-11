def optimal(n, edges, th):
    mat = [[float("inf")] * n for _ in range(n)]

    for i, j, wt in edges:
        mat[i][j] = wt
        mat[j][i] = wt

    for i in range(n):
        mat[i][i] = 0

    for via in range(n):
        for i in range(n):
            for j in range(n):
                if mat[i][via] == float("inf") or mat[via][j] == float("inf"):
                    continue
                mat[i][j] = min(mat[i][j], mat[i][via] + mat[via][j])

    cntMax = n + 1
    city = -1

    for i in range(n):
        count = 0
        for j in range(n):
            if mat[i][j] <= th:
                count += 1
        if count <= cntMax:
            cntMax = count
            city = i

    return city
