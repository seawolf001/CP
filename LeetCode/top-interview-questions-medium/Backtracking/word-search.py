from typing import List

class Solution:

    @staticmethod
    def get_directions():
        return ((-1,0), (0,1), (1,0), (0,-1))

    def exist(self, board: List[List[str]], word: str) -> bool:
        if (not board) or (not word):
            return False
        curr = ""
        m = len(board)
        n = len(board[0])
        for i in range(m):
            for j in range(n):
                if board[i][j]==word[0]:
                    found=self.dfs(board, word, 0, i, j, m, n)
                    if found:
                        return True
        return False

    def dfs(self, board, word, idx, i, j, m, n):
        if len(word)-1 == idx:
            return True
        char = board[i][j]
        board[i][j]='-1'
        for d in Solution.get_directions():
            x = i + d[0]
            y = j + d[1]
            if x < 0 or x >= m or y < 0 or y >= n:
                continue
            if board[x][y]==word[idx+1] and board[i][j]!=-1:
                if self.dfs(board, word, idx+1, x, y, m, n):
                    board[i][j]=char
                    return True
        board[i][j]=char
        return False

#  board = [['A','B','C','E'],['S','F','C','S'],['A','D','E','E']]
#  print(Solution().exist(board, "ABCCED"))
#  print(Solution().exist(board, "SEE"))
#  print(Solution().exist(board, "ABCB"))
