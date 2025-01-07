def optimal(begin, end, wordList):
    s = set(wordList)
    q = [[begin]]
    usedOnLevel = [begin]
    level = 0
    ans = []

    while q:
        vec = q.pop(0)

        if level < len(vec):
            level += 1
            for word in usedOnLevel:
                if word in s:
                    s.remove(word)
            usedOnLevel.clear()

        word = vec[-1]

        if word == end:
            if len(ans) == 0:
                ans.append(vec)
            elif len(ans[0]) == len(vec):
                ans.append(vec)

        for i in range(len(word)):
            for c in "abcdefghijklmnopqrstuvwxyz":
                newWord = word[:i] + c + word[i + 1 :]

                if newWord in s:
                    vec.append(newWord)
                    usedOnLevel.append(newWord)
                    q.append(vec[:])
                    vec.pop()

    return ans


print(optimal("hit", "cog", ["hot", "dot", "dog", "lot", "log", "cog"]))
