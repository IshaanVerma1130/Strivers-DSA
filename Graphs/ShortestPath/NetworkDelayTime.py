from heapq import heappop, heappush


def optimal(times, n, src):
    adj = [[] for _ in range(n + 1)]

    for i, j, wt in times:
        adj[i].append((j, wt))

    dis = [1e9 for _ in range(n + 1)]
    dis[0] = -1
    dis[src] = 0

    q = []
    heappush(q, (0, src))

    while q:
        d, node = heappop(q)

        for i, wt in adj[node]:
            if d + wt < dis[i]:
                dis[i] = d + wt
                heappush(q, (dis[i], i))

    for i in dis:
        if i == 1e9:
            return -1

    return max(dis)
