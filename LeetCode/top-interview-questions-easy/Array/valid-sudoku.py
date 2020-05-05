from typing import List

class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        for x in range(3):
            _x = x * 3
            for y in range(3):
                _y = y * 3
                h1 = {}
                for i in range(_x, _x+3):
                    for j in range(_y, _y+3):
                        # cell (i,j) in current 3x3
                        if board[i][j] == '.':
                            continue
                        if board[i][j] in h1:
                            return False
                        h1[board[i][j]] = True
                        # ith row
                        h2 = {}
                        for k in range(9):
                            if board[i][k] == '.':
                                continue
                            if board[i][k] in h2:
                                return False
                            h2[board[i][k]] = True
                        # jth column
                        h3 = {}
                        for k in range(9):
                            if board[k][j] == '.':
                                continue
                            if board[k][j] in h3:
                                return False
                            h3[board[k][j]] = True
        return True

