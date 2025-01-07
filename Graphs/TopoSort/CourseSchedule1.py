def optimal(pre: list[list[int]], num: int):
    adj = [[] for _ in range(num)]

    for x, y in pre:
        adj[x].append(y)

    inD = [0 for _ in range(num)]

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

    return True if len(ans) == num else False
