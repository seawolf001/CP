

class Solution:
    def reverse(self, x: int) -> int:
        y = 0
        negative = False
        MAX = 2**31
        if x < 0:
            x = -x
            negative = True
        while x:
            r = x % 10
            x = x // 10
            y = y * 10 + r
        if y > (MAX-1) or y < -1*MAX:
            return 0
        return y if not negative else -y
