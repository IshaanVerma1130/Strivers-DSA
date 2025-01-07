# Time complexity: O(N + E)
# Space complexity: O(N) + O(N) + O(N) = O(N)


class Solution:
    def dfsOfGraph(self, adj):
        vis = [0] * len(adj)
        dfs = []

        def recur(node):
            vis[node] = 1
            dfs.append(node)

            for i in adj[node]:
                if not vis[i]:
                    recur(i)

        recur(0)
        return dfs


if __name__ == "__main__":
    T = int(input())
    while T > 0:
        V, E = map(int, input().split())
        # Create adjacency list with V vertices
        adj = [[] for i in range(V)]  # List of lists (vector of vectors equivalent)

        # Reading edges
        for i in range(E):
            u, v = map(int, input().split())
            adj[u].append(v)
            adj[v].append(u)

        # Create an object of Solution class
        ob = Solution()
        ans = ob.dfsOfGraph(adj)

        # Printing the result
        for i in range(len(ans)):
            print(ans[i], end=" ")
        print()
        T -= 1
        print("~")
