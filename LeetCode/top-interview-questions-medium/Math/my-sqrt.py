


class Solution:
    def mySqrt(self, x: int) -> int:
        if x is 0 or x is 1:
            return x
        l, r = 0, x
        while l <= r:
            m = (l+r)//2
            if m**2 <= x < (m+1)**2:
                return m
            elif x < m**2:
                r = m
            else:
                l = m

