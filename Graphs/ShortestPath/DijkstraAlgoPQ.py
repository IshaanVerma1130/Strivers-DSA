import heapq as hq


# {dis, node}
def optimal(adj, src):
    pq = []

    dis = [float("inf") for _ in range(len(adj))]
    dis[src] = 0
    hq.heappush(pq, (0, src))

    while pq:
        d, node = hq.heappop(pq)

        for i, wt in adj[node]:
            if d + wt < dis[i]:
                dis[i] = d + wt
                hq.heappush(pq, (dis[i], i))

    return dis
