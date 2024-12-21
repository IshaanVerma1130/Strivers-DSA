def optimal(s: str, target: int):
    ans = []

    def recur(index: int, cur_res: list[str], cur_sum: int, prev: int):
        if index >= len(s):
            if cur_sum == target:
                ans.append("".join(cur_res))
            return

        for i in range(index, len(s)):
            cur_str = s[index : i + 1]
            cur_num = int(cur_str)

            if not cur_res:
                recur(i + 1, [cur_str], cur_num, cur_num)
            else:
                recur(i + 1, cur_res + ["+", cur_str], cur_sum + cur_num, cur_num)
                recur(i + 1, cur_res + ["-", cur_str], cur_sum - cur_num, -cur_num)
                recur(
                    i + 1,
                    cur_res + ["*", cur_str],
                    cur_sum - prev + cur_num * prev,
                    cur_num * prev,
                )

            if (
                s[index] == "0"
            ):  # only one iteration happend when we have 0 in the beginning of the string
                break

    recur(0, [], 0, 0)
    return ans


print(optimal("105", 5))
