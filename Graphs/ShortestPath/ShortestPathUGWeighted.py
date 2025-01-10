import heapq


def optimal(graph, v, e):
    adj = [[] for _ in range(v + 1)]

    for a, b, wt in graph:
        adj[a].append((b, wt))
        adj[b].append((a, wt))

    pq = []
    src = 1

    dis = [float("inf") for _ in range(v + 1)]
    dis[src] = 0

    heapq.heappush(pq, (0, src))

    parent = [i for i in range(v + 1)]

    while pq:
        d, node = heapq.heappop(pq)

        for i, wt in adj[node]:
            if d + wt < dis[i]:
                dis[i] = d + wt
                parent[i] = node
                heapq.heappush(pq, (dis[i], i))

    if dis[v] == float("inf"):
        return [-1]

    ans = []

    node = v

    while node != parent[node]:
        ans.append(node)
        node = parent[node]
    ans.append(src)

    ans.reverse()

    return ans


print(optimal([], 2, 0))
