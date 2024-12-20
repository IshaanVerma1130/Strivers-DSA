def optimal(mat: list[list[int]], s: str):
    def recur(i, j, k):
        if k == len(s):
            return True
        if i < 0 or i >= len(mat) or j < 0 or j >= len(mat[0]) or mat[i][j] != s[k]:
            return False

        temp = mat[i][j]
        mat[i][j] = ""

        if (
            recur(i + 1, j, k + 1)
            or recur(i - 1, j, k + 1)
            or recur(i, j + 1, k + 1)
            or recur(i, j - 1, k + 1)
        ):
            return True

        mat[i][j] = temp
        return False

    for i in range(len(mat)):
        for j in range(len(mat[0])):
            if mat[i][j] == s[0]:
                if recur(i, j, 0):
                    return True

    return False


mat = [["A", "B", "C", "E"], ["S", "F", "C", "S"], ["A", "D", "E", "E"]]
s = "ABCCED"

print(optimal(mat, s))
