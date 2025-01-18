def optimal(v, adj):
    marked = [0] * v
    vis = [0] * v
    tin = [0] * v
    low = [0] * v
    timer = 1

    def dfs(node, parent, timer):
        vis[node] = 1
        tin[node] = timer
        low[node] = timer
        child = 0

        for i in adj[node]:
            if i == parent:
                continue

            if vis[i] == 0:
                child += 1
                dfs(i, node, timer + 1)
                low[node] = min(low[node], low[i])

                if low[i] >= tin[node] and parent != -1:
                    marked[node] = 1
            else:
                low[node] = min(low[node], tin[i])

        if child > 1 and parent == -1:
            marked[node] = 1

    dfs(0, -1, timer)
    ans = []

    for i in range(v):
        if marked[i] == 1:
            ans.append(i)

    return ans
