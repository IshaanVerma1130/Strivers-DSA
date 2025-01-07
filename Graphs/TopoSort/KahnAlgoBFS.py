def optimal(adj):
    inDegree = [0] * len(adj)

    for al in adj:
        for i in al:
            inDegree[i] += 1

    q = []

    for i in range(len(inDegree)):
        if inDegree[i] == 0:
            q.append(i)
    ans = []
    while q:
        node = q.pop(0)
        ans.append(node)

        for i in adj[node]:
            inDegree[i] -= 1

            if inDegree[i] == 0:
                q.push(i)
    return ans
