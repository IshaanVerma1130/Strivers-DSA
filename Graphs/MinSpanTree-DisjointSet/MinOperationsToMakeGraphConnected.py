class DS:
    def __init__(self, n):
        self.parent = [i for i in range(n + 1)]
        self.__size = [1] * (n + 1)

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

        if self.__size[uP] < self.__size[vP]:
            self.__size[vP] += self.__size[uP]
            self.parent[uP] = vP
        else:
            self.__size[uP] += self.__size[vP]
            self.parent[vP] = uP


def optimal(n, edges):
    extras = 0
    d = DS(n)
    for u, v in edges:
        if d.findP(u) == d.findP(v):
            extras += 1
        else:
            d.union(u, v)

    connected = 0

    for i in range(n):
        if d.parent[i] == i:
            connected += 1

    if extras >= connected - 1:
        return connected - 1
    return -1


print(optimal(4, [[0, 1], [0, 2], [1, 2]]))
