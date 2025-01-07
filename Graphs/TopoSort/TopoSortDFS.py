def optimal(adj):
    n = len(adj)
    vis = [0 for _ in range(n)]
    st = []

    def dfs(node):
        vis[node] = 1

        for i in adj[node]:
            if vis[i] == 0:
                dfs(i)

        st.append(node)

    for i in range(n):
        if vis[i] == 0:
            dfs(i)

    st.reverse()
    return st


print(optimal([[], [0], [0], [0]]))
