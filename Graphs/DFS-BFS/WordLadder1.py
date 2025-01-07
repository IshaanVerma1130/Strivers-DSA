def optimal(begin, end, wordList):
    s = set(wordList)
    q = []

    q.append((begin, 1))

    while q:
        word, count = q.pop(0)
        if word == end:
            return count

        for i in range(len(word)):
            for c in "abcdefghijklmnopqrstuvwxyz":
                new = word[:i] + c + word[i + 1 :]
                if new in s:
                    q.append(new, count + 1)
                    s.remove(new)

    return 0
