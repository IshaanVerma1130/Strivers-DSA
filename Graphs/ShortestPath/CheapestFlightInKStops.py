from heapq import heappush, heappop


def optimal(n, graph, src, dst, k):
    adj = [[] for _ in range(n)]

    for s, d, p in graph:
        adj[s].append((d, p))

    q = [(0, src, 0)]

    dis = [1e9 for _ in range(n)]
    dis[src] = 0

    while q:
        stops, node, cost = heappop(q)

        if stops > k:
            continue

        for i, wt in adj[node]:
            if cost + wt < dis[i] and stops <= k:
                dis[i] = cost + wt
                heappush(q, (stops + 1, i, dis[i]))

    if dis[dst] == 1e9:
        return -1

    else:
        return dis[dst]
