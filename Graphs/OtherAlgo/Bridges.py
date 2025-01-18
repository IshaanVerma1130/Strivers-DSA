def optimal(n, edges):
    adj = [[] for _ in range(n)]

    for i, j in edges:
        adj[i].append(j)
        adj[j].append(i)

    timer = 1
    tin = [0] * n
    low = [0] * n

    vis = [0] * n

    bridges = []

    def dfs(node, parent, timer):
        vis[node] = 1

        tin[node] = timer
        low[node] = timer

        for i in adj[node]:
            if i == parent:
                continue
            if vis[i] == 0:
                dfs(i, node, timer + 1)
                low[node] = min(low[node], low[i])

                if low[i] > tin[node]:
                    bridges.append((node, i))
            else:
                low[node] = min(low[node], low[i])

    dfs(0, -1, timer)
    return bridges
