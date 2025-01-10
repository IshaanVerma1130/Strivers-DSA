def optimal(dic, k):
    adj = [[] for _ in range(k)]
    n = len(dic)
    for i in range(n - 1):
        s1 = dic[i]
        s2 = dic[i + 1]

        min_len = min(len(s1), len(s2))

        for j in range(min_len):
            if s1[j] != s2[j]:
                adj[ord(s1[j]) - ord("a")].append(ord(s2[j]) - ord("a"))
                break

    inD = [0 for _ in range(k)]

    for al in adj:
        for i in al:
            inD[i] += 1

    q = []

    for i in range(len(inD)):
        if inD[i] == 0:
            q.append(i)

    ans = []

    while q:
        node = q.pop(0)
        ans.append(node)

        for i in adj[node]:
            inD[i] -= 1

            if inD[i] == 0:
                q.append(i)

    if len(ans) == k:
        st = ""
        for i in ans:
            st += chr(i + ord("a"))
        return st
    return ""


print(
    optimal(
        ["dhhid", "dahi", "cedg", "fg", "gdah", "i", "gbdei", "hbgf", "e", "ddde"], 9
    )
)
