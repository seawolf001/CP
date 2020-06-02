

from typing import List

class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        m = len(matrix)
        n = len(matrix[0])
        for i in range(m):
            for j in range(n):
                if matrix[i][j]==0:
                    if not isinstance(matrix[i][0], dict):
                        matrix[i][0] = {}
                    if not isinstance(matrix[0][j], dict):
                         matrix[0][j] = {}
                    matrix[i][0]['R'] = True
                    matrix[0][j]['C'] = True
        for i in range(m):
            for j in range(n):
                if isinstance(matrix[i][j], dict):
                    continue
                if isinstance(matrix[i][0], dict) and matrix[i][0].get('R', False):
                    matrix[i][j]=0
                if isinstance(matrix[0][j], dict) and matrix[0][j].get('C', False):
                    matrix[i][j]=0
        for i in range(m):
            if isinstance(matrix[i][0], dict):
                matrix[i][0] = 0
        for j in range(n):
            if isinstance(matrix[0][j], dict):
                matrix[0][j] = 0

