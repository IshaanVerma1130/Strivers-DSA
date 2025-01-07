def optimal(adj):
    vis = [0] * len(adj)
    q = []

    def bfs(src):
        q.append((src, -1))
        vis[src] = 1

        while q:
            node, parent = q.pop(0)

            for n in adj[node]:
                if vis[n] == 0:
                    vis[n] = 1
                    q.append((n, node))
                elif n != parent:
                    return True

        return False

    for i in range(len(adj)):
        if vis[i] == 0:
            if bfs(i):
                return True

    return False


print(optimal([[1, 2], [0, 2], [0, 1]]))  # True
