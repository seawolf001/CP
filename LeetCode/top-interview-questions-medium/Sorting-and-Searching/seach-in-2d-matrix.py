

class Solution:
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        m = len(matrix)
        if not m:
            return False
        n = len(matrix[0])
        i, j = 0, n-1
        while i < m and j >= 0:
            curr = matrix[i][j]
            if curr == target:
                return True
            elif curr > target:
                j -= 1
            else:
                i += 1
        return False

