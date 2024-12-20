def optimal(n):
    ans = []
    board = ["." * n] * n
    lower_diagonal = [0] * (2 * n - 1)
    upper_diagonal = [0] * (2 * n - 1)
    row_occupied_column = [0] * n

    def is_valid(row, col):
        return (
            lower_diagonal[row + col] == 0
            and row_occupied_column[row] == 0
            and upper_diagonal[(n - 1 - row) + col] == 0
        )

    def recur(col):
        if col >= n:
            ans.append(board[:])
            return

        for row in range(n):
            if is_valid(row, col):
                lower_diagonal[row + col] = 1
                row_occupied_column[row] = 1
                upper_diagonal[(n - 1 - row) + col] = 1
                board[row] = board[row][:col] + "Q" + board[row][col + 1 :]
                recur(col + 1)
                board[row] = board[row][:col] + "." + board[row][col + 1 :]
                lower_diagonal[row + col] = 0
                row_occupied_column[row] = 0
                upper_diagonal[(n - 1 - row) + col] = 0

    recur(0)
    return ans


ans = optimal(4)

for i in ans:
    for j in i:
        print(j, end="\n")
    print()
