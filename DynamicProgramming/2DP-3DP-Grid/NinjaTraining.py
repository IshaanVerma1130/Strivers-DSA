def optimal(arr):
    n = len(arr)

    dp = [[-1, -1, -1, -1] for _ in range(n + 1)]

    def recur(day, lastTask):
        if day == 0:
            maxi = -1
            for task in [0, 1, 2]:
                if task != lastTask:
                    maxi = max(maxi, arr[0][task])
            return maxi

        if dp[day][lastTask] != -1:
            return dp[day][lastTask]

        maxi = -1

        for task in [0, 1, 2]:
            if task != lastTask:
                points = arr[day][task] + recur(day - 1, task)
                maxi = max(maxi, points)

        dp[day][lastTask] = maxi
        return maxi

    return recur(n - 1, 3)
