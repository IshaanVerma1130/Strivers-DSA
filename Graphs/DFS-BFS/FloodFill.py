def optimal(image, sr, sc, color):
    initial_color = image[sr][sc]

    if initial_color == color:
        return image

    vis = image.copy()
    n, m = len(image), len(image[0])

    def dfs(i, j):
        if (
            i < 0
            or j < 0
            or j >= m
            or i >= n
            or vis[i][j] == color
            or image[i][j] != initial_color
        ):
            return

        vis[i][j] = color

        dfs(i + 1, j)
        dfs(i - 1, j)
        dfs(i, j + 1)
        dfs(i, j - 1)

    dfs(sr, sc)
    return vis


image = [[1, 1, 1], [1, 1, 0], [1, 0, 1]]
sr = 1
sc = 1
color = 2

print(optimal(image, sr, sc, color))  # [[2, 2, 2], [2, 2, 0], [2, 0, 1]]
