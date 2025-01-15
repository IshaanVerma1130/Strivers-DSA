class disjointSet:
    def __init__(self, n):
        self.__rank = [0] * (n + 1)
        self.__parent = [i for i in range(n + 1)]
        self.__size = [1] * (n + 1)

    def findUPar(self, node):
        if node == self.__parent[node]:
            return node
        self.__parent[node] = self.findUPar(self.__parent[node])
        return self.__parent[node]

    def unionByRank(self, u, v):
        ulp_u = self.findUPar(u)
        ulp_v = self.findUPar(v)

        if ulp_u == ulp_v:
            return

        if self.__rank[ulp_u] < self.__rank[ulp_v]:
            self.__parent[ulp_u] = ulp_v
        elif self.__rank[ulp_v] < self.__rank[ulp_u]:
            self.__parent[ulp_v] = ulp_u
        else:
            self.__parent[ulp_u] = ulp_v
            self.__rank[ulp_v] += 1

    def unionBySize(self, u, v):
        ulp_u = self.findUPar(u)
        ulp_v = self.findUPar(v)

        if ulp_u == ulp_v:
            return

        if self.__size[ulp_u] < self.__size[ulp_v]:
            self.__parent[ulp_u] = ulp_v
            self.__size[ulp_v] += self.__size[ulp_u]
        elif self.__size[ulp_v] <= self.__size[ulp_u]:
            self.__parent[ulp_v] = ulp_u
            self.__size[ulp_u] = self.__size[ulp_v]


dj = disjointSet(7)
dj.unionBySize(1, 2)
dj.unionBySize(2, 3)
dj.unionBySize(4, 5)
dj.unionBySize(6, 7)
dj.unionBySize(5, 6)

print(dj.findUPar(3) == dj.findUPar(7))

dj.unionBySize(3, 7)

print(dj.findUPar(3) == dj.findUPar(7))
