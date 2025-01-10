# Topo sort array.
# while topo sort is not empty, calculate distances.


def optimal(graph, ver, edg):
    adj = [[] for _ in range(ver)]

    for u, v, wt in graph:
        adj[u].append((v, wt))

    vis = [0] * ver
    st = []

    def dfs(node):
        vis[node] = 1

        for i, wt in adj[node]:
            if vis[i] == 0:
                dfs(i)

        st.append(node)

    for i in range(ver):
        if vis[i] == 0:
            dfs(i)

    dis = [float("inf") for _ in range(ver)]
    dis[0] = 0

    while st:
        node = st.pop()

        for i, wt in adj[node]:
            if wt + dis[node] < dis[i]:
                dis[i] = wt + dis[node]
    for i in range(len(dis)):
        if dis[i] == float("inf"):
            dis[i] = -1

    return dis
