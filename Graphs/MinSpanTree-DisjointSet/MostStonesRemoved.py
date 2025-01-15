class DS:
    def __init__(self, n):
        self.__parent = [i for i in range(n + 1)]
        self.__size = [1 for _ in range(n + 1)]

    def findP(self, u):
        if self.__parent[u] == u:
            return u
        self.__parent[u] = self.findP(self.__parent[u])
        return self.__parent[u]

    def union(self, u, v):
        uP = self.findP(u)
        vP = self.findP(v)

        if uP == vP:
            return

        if self.__size[uP] < self.__size[vP]:
            self.__size[vP] += self.__size[uP]
            self.__parent[uP] = self.__parent[vP]
        else:
            self.__size[uP] += self.__size[vP]
            self.__parent[vP] = self.__parent[uP]


def optimal(stones):
    maxRow, maxCol = 0, 0

    for i, j in stones:
        maxRow = max(maxRow, i)
        maxCol = max(maxCol, j)

    d = DS(maxRow + maxCol + 1)

    s = dict()
    for i, j in stones:
        j = j + maxRow + 1
        d.union(i, j)
        s[i] = 1
        s[j] = 1

    count = 0
    for key in s:
        if key == d.findP(key):
            count += 1

    return len(stones) - count


print(optimal([[0, 1], [1, 0], [1, 1]]))
