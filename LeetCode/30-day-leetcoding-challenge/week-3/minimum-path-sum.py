
from typing import List

class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        if not grid:
            return 0
        m = len(grid)
        n = len(grid[0])
        dp = [[0]*n for x in range(m)]
        dp[0][0] = grid[0][0]
        for x in range(m):
            for y in range(n):
                if x==0 and y==0:
                    dp[x][y] = grid[x][y]
                elif x==0 and y > 0:
                    dp[x][y] = dp[x][y-1] + grid[x][y]
                elif x > 0 and y==0:
                    dp[x][y] = dp[x-1][y] + grid[x][y]
                else:
                    dp[x][y] = min(dp[x-1][y], dp[x][y-1]) + grid[x][y]
        return dp[m-1][n-1]
