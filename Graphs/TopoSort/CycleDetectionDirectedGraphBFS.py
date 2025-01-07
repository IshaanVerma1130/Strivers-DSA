def optimal(adj):
    inD = [0] * len(adj)

    for al in adj:
        for i in al:
            inD[i] += 1

    q = []

    for i in range(len(inD)):
        if inD[i] == 0:
            q.append(i)
    ans = []
    while q:
        node = q.pop(0)
        ans.append(node)
        for i in adj[node]:
            inD[i] -= 1

            if inD[i] == 0:
                q.append(i)

    return False if len(ans) < len(adj) else True
