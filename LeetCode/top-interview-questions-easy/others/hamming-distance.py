
class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        n = x^y
        c = 0
        while n:
            n &= n-1
            c += 1
        return c
