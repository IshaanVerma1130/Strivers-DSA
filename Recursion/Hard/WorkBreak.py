def optimal(s: str, wordDict: list[str]):
    words = set(wordDict)

    def recur(s):
        if s == "":
            return True

        for word in words:
            if s.startswith(word):
                if recur(s[len(word) :]):
                    return True

        return False

    return recur(s)


print(optimal("cars", ["car", "ca", "rs"]))
