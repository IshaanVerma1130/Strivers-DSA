def optimal(isConnected):
    n = len(isConnected)

    adj = [[] for _ in range(n)]

    for i in range(n):
        for j in range(n):
            if isConnected[i][j] == 1 and i != j:
                adj[i].append(j)
                adj[j].append(i)

    vis = [0] * n
    count = 0

    def dfs(node):
        vis[node] = 1
        for i in adj[node]:
            if not vis[i]:
                dfs(i)

    for i in range(n):
        if vis[i] == 0:
            count += 1
            dfs(i)

    return count


matrix = [[1, 1, 0], [1, 1, 0], [0, 0, 1]]
print(optimal(matrix))  # 2
