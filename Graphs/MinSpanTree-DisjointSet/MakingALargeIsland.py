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


def optimal(mat):
    n = len(mat)
    m = len(mat[0])

    d = DS(n * m)

    for i in range(n):
        for j in range(m):
            if mat[i][j] == 0:
                continue

            for dr, dc in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
                newR = i + dr
                newC = j + dc

                if (
                    newC >= 0
                    and newR >= 0
                    and newC < m
                    and newR < n
                    and mat[newR][newC] == 1
                ):
                    node = n * i + j
                    adjNode = newR * n + newC
                    d.union(node, adjNode)
    maxSize = 0

    for i in range(n):
        for j in range(m):
            if mat[i][j] == 1:
                continue

            s = set()

            for dr, dc in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
                newR = i + dr
                newC = j + dc

                if (
                    newC >= 0
                    and newR >= 0
                    and newC < m
                    and newR < n
                    and mat[newR][newC] == 1
                ):
                    adjNode = newR * n + newC
                    s.add(d.findP(adjNode))

            size = 0
            for comp in s:
                size += d.size[comp]
            maxSize = max(maxSize, size + 1)

    for i in range(n * m):
        maxSize = max(maxSize, d.size[d.findP(i)])

    return maxSize
