def optinal(digits):
    if not digits:
        return 0

    mapping = {
        "2": "abc",
        "3": "def",
        "4": "ghi",
        "5": "jkl",
        "6": "mno",
        "7": "pqrs",
        "8": "tuv",
        "9": "wxyz",
    }

    ans = []

    def recur(index, digi):
        if index == len(digits):
            ans.append(digi)
            return

        for letter in mapping[digits[index]]:
            recur(index + 1, digi + letter)

    recur(0, "")
    return ans
