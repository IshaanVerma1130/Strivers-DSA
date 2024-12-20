def optimal(n, k):
    fact = 1
    numbers = []
    ans = ""

    for i in range(1, n):
        fact *= i
        numbers.append(i)

    numbers.append(n)
    k -= 1
    while numbers:
        ans += str(numbers.pop(k // fact))
        k = k % fact
        if numbers:
            fact = fact // len(numbers)

    return ans


print(optimal(3, 3))  # 213
