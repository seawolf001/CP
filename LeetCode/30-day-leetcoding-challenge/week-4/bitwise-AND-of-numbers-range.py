
# This is getting TLE

class Solution:
    def rangeBitwiseAnd(self, m: int, n: int) -> int:
        res = m
        for x in range(m+1, n+1):
            res = res & x
        return res

if __name__ == '__main__':
    s = Solution()
    assert s.rangeBitwiseAnd(5,7) == 4
    assert s.rangeBitwiseAnd(0,1) == 0
