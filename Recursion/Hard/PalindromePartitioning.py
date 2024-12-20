def optimal(s: str):
    ans = []
    ds = []

    def is_palindrome(start, end):
        while start < end:
            if s[start] != s[end]:
                return False
            start += 1
            end -= 1
        return True

    def recur(index):
        if index == len(s):
            ans.append(ds[:])
            return

        for i in range(index, len(s)):
            if is_palindrome(index, i):
                ds.append(s[index : i + 1])
                recur(i + 1)
                ds.pop()

    recur(0)
    return ans


print(optimal("aab"))
