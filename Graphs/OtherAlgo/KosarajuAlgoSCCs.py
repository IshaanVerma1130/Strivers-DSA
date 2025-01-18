def optimal(adj):
    v = len(adj)
    vis = [0] * v
    st = []

    def dfs(node):
        vis[node] = 1

        for i in adj[node]:
            if vis[i] == 0:
                dfs(i)

        st.append(node)

    for i in range(v):
        if vis[i] == 0:
            dfs(i)

    adjRev = [[] for _ in range(v)]

    for i in range(v):
        vis[i] = 0
        for aNode in adj[i]:
            adjRev[aNode].append(i)

    def dfs2(node):
        vis[node] = 1

        for i in adjRev[node]:
            if vis[i] == 0:
                dfs2(i)

    scc = 0

    while st:
        node = st.pop()

        if vis[node] == 0:
            scc += 1
            dfs2(node)

    return scc


print(optimal([[2, 3], [0], [1], [4], []]))
