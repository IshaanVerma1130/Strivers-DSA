def optimal(mat):
    n = len(mat)

    for i in range(n):
        for j in range(n):
            if mat[i][j] == -1:
                mat[i][j] = 1000000000

    for via in range(n):
        for i in range(n):
            for j in range(n):
                mat[i][j] = min(mat[i][j], mat[i][via] + mat[via][j])

    for i in range(n):
        for j in range(n):
            if mat[i][j] == 1000000000:
                mat[i][j] = -1
