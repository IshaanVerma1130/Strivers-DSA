def optimal(mat: list[list[int]]):
    ds = []
    ans = []

    def recur(i, j):
        if i == len(mat) - 1 and j == len(mat[0]) - 1:
            ans.append("".join(ds))
            return

        if i >= len(mat) or i < 0 or j >= len(mat[0]) or j < 0 or mat[i][j] == 0:
            return

        temp = mat[i][j]
        mat[i][j] = 0

        ds.append("D")
        recur(i + 1, j)
        ds.pop()

        ds.append("L")
        recur(i, j - 1)
        ds.pop()

        ds.append("R")
        recur(i, j + 1)
        ds.pop()

        ds.append("U")
        recur(i - 1, j)
        ds.pop()

        mat[i][j] = temp

    recur(0, 0)
    return ans


print(
    optimal([[1, 0, 0, 0], [1, 1, 0, 1], [1, 1, 0, 0], [0, 1, 1, 1]])
)  # ['DDRDRR', 'DRDDRR']
