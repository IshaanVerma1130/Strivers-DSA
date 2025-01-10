def optimal(adj, src):
    # adj = [[] for _ in range(len(mat))]

    # for x, y in mat:
    #     adj[x].append(y)
    #     adj[y].append(x)

    q = []
    n = len(adj)

    dis = [float("inf")] * n
    dis[src] = 0
    q.append(src)

    while q:
        node = q.pop(0)
        d = dis[node]
        for i in adj[node]:
            if d + 1 < dis[i]:
                q.append(i)
                dis[i] = d + 1

    for i in range(len(dis)):
        if dis[i] == float("inf"):
            dis[i] = -1
    return dis


print(
    optimal(
        [[1, 3], [0, 2], [1, 6], [0, 4], [3, 5], [4, 6], [2, 5, 7, 8], [6, 8], [7, 6]],
        0,
    )
)
