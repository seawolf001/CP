

from typing import List

direction = (
        (-1, 0),
        (0, -1),
        (1, 0),
        (0 ,1)
    )

class Solution:
    def dfs(self, x, y, vis, m, n, grid):
        vis[x][y] = True
        for d in direction:
            _x = x + d[0]
            _y = y + d[1]
            if _x < 0 or _x >= m or _y < 0 or _y >= n:
                pass
            elif not vis[_x][_y] and grid[_x][_y] == '1':
                self.dfs(_x, _y, vis, m, n, grid)

    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid: return 0
        m = len(grid)
        n = len(grid[0])
        vis = [[False]*n for i in range(m)]
        count = 0
        for x in range(m):
            for y in range(n):
                if not vis[x][y] and grid[x][y]=='1':
                    self.dfs(x, y, vis, m, n, grid)
                    count += 1
        return count

