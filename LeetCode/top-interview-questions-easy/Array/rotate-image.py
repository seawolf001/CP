from typing import List

class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        for x in range(len(matrix)):
            for y in range(x+1):
                matrix[x][y], matrix[y][x] = matrix[y][x], matrix[x][y]
        for x in range(len(matrix)):
            matrix[x].reverse()
