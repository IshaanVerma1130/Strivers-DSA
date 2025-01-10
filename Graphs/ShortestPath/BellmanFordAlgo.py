def optimal(v, edges, src):
    dis = [int(1e8) for _ in range(v)]
    dis[src] = 0

    for _ in range(v - 1):
        for i, j, wt in edges:
            if dis[i] + wt < dis[j] and dis[i] != int(1e8):
                dis[j] = wt + dis[i]

    for i, j, wt in edges:
        if dis[i] + wt < dis[j] and dis[i] != int(1e8):
            return [-1]

    return dis
