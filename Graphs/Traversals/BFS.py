from typing import List


# Time complexity: O(n) + O(2E) = O(V + 2E)
# Space complexity: O(n) + O(n) + O(n) = O(n)


class Solution:
    # Function to return Breadth First Traversal of given graph.
    def bfsOfGraph(self, adj: List[List[int]]) -> List[int]:
        bfs = []

        q = []

        vis = [0] * len(adj)
        vis[0] = 1

        q.append(0)

        while q:
            node = q.pop(0)
            bfs.append(node)

            for i in adj[node]:
                if not vis[i]:
                    vis[i] = 1
                    q.append(i)

        return bfs


if __name__ == "__main__":
    T = int(input())  # Number of test cases
    for i in range(T):
        V = int(input())  # Number of vertices
        E = int(input())  # Number of edges
        adj = [[] for i in range(V)]  # Adjacency list
        for _ in range(E):
            u, v = map(int, input().split())
            adj[u].append(v)
            adj[v].append(u)  # Undirected graph

        ob = Solution()
        ans = ob.bfsOfGraph(adj)
        print(" ".join(map(str, ans)))
