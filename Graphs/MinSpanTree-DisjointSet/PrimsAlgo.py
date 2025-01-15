from heapq import heappop, heappush


# we also keep parent if we want the tree. and check if parent == -1
def optiman(n, adj):
    vis = [0] * n
    # wt, node, parent
    q = [(0, 0)]
    s = 0

    while q:
        wt, node = heappop(q)

        if vis[node] == 1:
            continue

        vis[node] = 1
        s += wt

        for i, wt in adj[node]:
            if vis[i] == 0:
                heappush(q, (wt, i))

    return s
