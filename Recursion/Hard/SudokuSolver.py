def optimal(board):
    def is_valid(row, col, ch):
        for i in range(9):
            if board[row][i] == ch:
                return False
            if board[i][col] == ch:
                return False
            if board[3 * (row // 3) + i // 3][3 * (col // 3) + i % 3] == ch:
                return False
        return True

    def recur(board):
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] == ".":
                    for ch in "123456789":
                        if is_valid(i, j, ch):
                            board[i][j] = ch
                            if recur(board):
                                return True
                            board[i][j] = "."
                    return False

        return True

    recur(board)


board = [
    [".", ".", ".", ".", ".", ".", ".", ".", "."],
    [".", "9", ".", ".", "1", ".", ".", "3", "."],
    [".", ".", "6", ".", "2", ".", "7", ".", "."],
    [".", ".", ".", "3", ".", "4", ".", ".", "."],
    ["2", "1", ".", ".", ".", ".", ".", "9", "8"],
    [".", ".", ".", ".", ".", ".", ".", ".", "."],
    [".", ".", "2", "5", ".", "6", "4", ".", "."],
    [".", "8", ".", ".", ".", ".", ".", "1", "."],
    [".", ".", ".", ".", ".", ".", ".", ".", "."],
]

optimal(board)

for i in board:
    print(" ".join(i), end="\n")
