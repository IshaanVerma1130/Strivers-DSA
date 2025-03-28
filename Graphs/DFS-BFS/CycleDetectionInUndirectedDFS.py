def optimal(adj):
    vis = [0] * len(adj)

    def dfs(node, parent):
        vis[node] = 1

        for n in adj[node]:
            if vis[n] == 0:
                if dfs(n, node) == True:
                    return True
            elif n != parent:
                return True

        return False

    for i in range(len(adj)):
        if vis[i] == 0:
            if dfs(i, -1) == True:
                return True

    return False


print(optimal([[1, 2], [0, 2], [0, 1]]))  # True
