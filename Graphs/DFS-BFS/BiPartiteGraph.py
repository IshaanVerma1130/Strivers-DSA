def optimal(adj):
    n = len(adj)

    color = [-1 for _ in range(n)]

    def dfs(node, col):
        color[i] = col

        for i in adj[node]:
            if color[i] == -1:
                if dfs(i, not col) == False:
                    return False
            elif color[i] == col:
                return False

        return True

    for i in range(n):
        if color[i] == -1:
            if dfs(i, 0) == False:
                return False

    return True
