class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        cols, posDiag, negDiag = set(), set(), set()
        res = []

        board = [["."] * n for _ in range(n)]

        def backtrack(r):
            if r == len(board):
                copy = ["".join(r) for r in board]
                res.append(copy)
                return
            
            for c in range(len(board[r])):
                if c in cols or r + c in posDiag or r - c in negDiag:
                    continue
                
                board[r][c] = "Q"
                cols.add(c)
                posDiag.add(r + c)
                negDiag.add(r - c)

                backtrack(r + 1)

                board[r][c] = "."
                cols.remove(c)
                posDiag.remove(r + c)
                negDiag.remove(r - c)
        
        backtrack(0)
        return res

