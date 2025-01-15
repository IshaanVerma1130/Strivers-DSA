class DS:
    def __init__(self, n):
        self.parent = [i for i in range(n + 1)]
        self.size = [1 for i in range(n + 1)]

    def findP(self, u):
        if self.parent[u] == u:
            return u
        self.parent[u] = self.findP(self.parent[u])
        return self.parent[u]

    def union(self, u, v):
        uP = self.findP(u)
        vP = self.findP(v)

        if uP == vP:
            return

        if self.size[uP] < self.size[vP]:
            self.size[vP] += self.size[uP]
            self.parent[uP] = vP
        else:
            self.size[uP] += self.size[vP]
            self.parent[vP] = uP


def optimal(ops):
    n = len(ops)
    m = len(ops[0])

    d = DS(n * m)

    vis = [[0] * m for _ in range(n)]
    ans = []
    count = 0

    for i, j in ops:
        if vis[i][j] == 1:
            ans.append(count)
            continue

        vis[i][j] = 1
        count += 1

        for dr, dc in [(1, 0), (1, 0), (0, 1), (0, -1)]:
            newR = i + dr
            newC = j + dc

            if newR >= 0 and newC >= 0 and newR < n and newC < m:
                if vis[newR][newC] == 1:
                    node = i * n + j
                    adjNode = newR * n + newC

                    if d.findP(node) != d.findP(adjNode):
                        d.union(node, adjNode)
                        count -= 1

    return ans
