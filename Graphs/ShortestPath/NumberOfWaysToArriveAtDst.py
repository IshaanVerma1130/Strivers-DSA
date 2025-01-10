from heapq import heappop, heappush


def optimal(graph, n):
    adj = [[] for _ in range(n)]

    for i, j, wt in graph:
        adj[i].append((j, wt))
        adj[j].append((i, wt))

    dis = [float("inf") for _ in range(n)]
    dis[0] = 0

    ways = [0 for _ in range(n)]
    ways[0] = 1

    q = []
    heappush(q, (0, 0))

    m = 1e9 + 7

    while q:
        d, node = heappop(q)

        for i, wt in adj[node]:
            if d + wt < dis[i]:
                dis[i] = d + wt
                heappush(q, (dis[i], i))
                ways[i] = ways[node]
            elif d + wt == dis[i]:
                ways[i] = (ways[i] + ways[node]) % m

    return int(ways[n - 1] % m)
