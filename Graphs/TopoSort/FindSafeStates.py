def optimal(adj):
    adjRev = [[] for _ in range(len(adj))]
    inD = [0 for _ in range(len(adjRev))]

    for i in range(len(adj)):
        for j in adj[i]:
            adjRev[j].append(i)
            inD[i] += 1

    q = []

    for i in range(len(inD)):
        if inD[i] == 0:
            q.append(i)

    ans = []

    while q:
        node = q.pop(0)
        ans.append(node)

        for i in adjRev[node]:
            inD[i] -= 1

            if inD[i] == 0:
                q.append(i)

    ans.sort()

    return ans
