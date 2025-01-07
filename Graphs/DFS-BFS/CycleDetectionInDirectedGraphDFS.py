def optimal(adj):
    n = len(adj)
    vis = [0 for _ in range(n)]
    pathVis = [0 for _ in range(n)]

    def dfs(node):
        vis[node] = 1
        pathVis[node] = 1

        for i in adj[node]:
            if vis[i] == 0:
                if dfs(i) == True:
                    return True
            elif pathVis[i] == 1:
                return True

        pathVis[node] = 0
        return False

    for i in range(n):
        if vis[i] == 0:
            if dfs(i) == True:
                return True

    return False


print(optimal([[0, 1], [1, 2], [2, 3], [3, 3]]))
