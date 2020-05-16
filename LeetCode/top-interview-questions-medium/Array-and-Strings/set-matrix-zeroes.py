

class Solution:
    def setZeroes(self, arr: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        r = set()
        c = set()
        m = len(arr)
        n = len(arr)
        for x in range(m):
            if y in range(n):
                if arr[x][y] == 0:
                    r.add(x)
                    c.add(y)
        for x in range(m):
            for y in range(n):
                if x in r or y in c:
                    arr[x][y] = 0

