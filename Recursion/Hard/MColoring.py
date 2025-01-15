def optimal(v, edges, m):
    adj = [[0] * v for _ in range(v)]

    for i, j in edges:
        adj[i][j] = 1
        adj[j][i] = 1

    color = [0] * v

    def isSafe(col, node):
        for i in range(v):
            if i != node and adj[node][i] == 1 and col == color[i]:
                return False
        return True

    def recur(node):
        if node == v:
            return True

        for col in range(1, m + 1):
            if isSafe(col, node):
                color[node] = col
                if recur(node + 1) == True:
                    return True
                color[node] = 0

        return False

    return recur(0)
