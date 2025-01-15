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


def optimal(acc):
    n = len(acc)
    idToName = dict()
    d = DS(n)

    for name in range(n):
        for j in range(1, len(acc[name])):
            id = acc[name][j]

            if id not in idToName:
                idToName[id] = name
            else:
                d.union(name, idToName[id])

    merged = [[] for _ in range(n)]

    for id, name in idToName.items():
        parent = d.findP(name)
        merged[parent].append(id)

    ans = []

    for i in range(n):
        if not merged[i]:
            continue

        merged[i].sort()
        temp = []
        temp.append(acc[i][0])

        for mail in merged[i]:
            temp.append(mail)

        ans.append(temp)

    return ans
