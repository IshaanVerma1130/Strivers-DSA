def optimal(s, k):
    n = len(s)
    i = 0
    j = 0
    max_len = 0
    char_count = {}

    while j < n:
        char_count[s[j]] = char_count.get(s[j], 0) + 1

        if len(char_count) > k:
            char_count[s[i]] -= 1
            if char_count[s[i]] == 0:
                del char_count[s[i]]
            i += 1

        if len(char_count) <= k:
            max_len = max(max_len, j - i + 1)
        j += 1

    return max_len


if __name__ == "__main__":
    s = "aabacbebebe"
    k = 3
    print(optimal(s, k))
