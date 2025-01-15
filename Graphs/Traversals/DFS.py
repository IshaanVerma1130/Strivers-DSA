# Time complexity: O(N + 2E)
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
