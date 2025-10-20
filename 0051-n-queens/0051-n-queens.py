class Solution:
    def solve(self, col, board, n, leftRow, upperDiagonal, lowerDiagonal, ans):
        # If all queens are placed
        if col == n:
            ans.append(["".join(row) for row in board])
            return

        # Iterate through rows
        for row in range(n):
            # Check safety
            if leftRow[row] == 0 and lowerDiagonal[row + col] == 0 and \
               upperDiagonal[n - 1 + col - row] == 0:

                # Place queen
                board[row][col] = 'Q'
                leftRow[row] = lowerDiagonal[row + col] = upperDiagonal[n - 1 + col - row] = 1

                # Recurse
                self.solve(col + 1, board, n, leftRow, upperDiagonal, lowerDiagonal, ans)

                # Backtrack
                board[row][col] = '.'
                leftRow[row] = lowerDiagonal[row + col] = upperDiagonal[n - 1 + col - row] = 0

    def solveNQueens(self, n: int) -> List[List[str]]:
        ans = []
        board = [['.' for _ in range(n)] for _ in range(n)]
        leftRow = [0]*n
        lowerDiagonal = [0] * (2 * n-1)
        upperDiagonal = [0] * (2 * n-1)
        self.solve(0, board, n, leftRow, upperDiagonal, lowerDiagonal, ans)
        return ans

