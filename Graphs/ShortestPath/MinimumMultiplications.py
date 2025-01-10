def optimal(start, end, arr):
    dis = [float("inf") for _ in range(100000)]
    dis[start] = 0
    q = [(0, start)]
    if start == end:
        return 0
    while q:
        steps, node = q.pop(0)

        for i in arr:
            mul = (i * node) % 100000
            if steps + 1 < dis[mul]:
                dis[mul] = steps + 1
                if mul == end:
                    return steps + 1
                q.append((steps + 1, mul))

    return -1


print(optimal(3, 30, [2, 5, 7]))
