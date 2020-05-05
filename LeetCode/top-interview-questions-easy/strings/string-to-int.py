
import string

class Solution:
    def myAtoi(self, s: str) -> int:
        s = s.lstrip()
        if not s: return 0
        if not s[0] in "+-0123456789": return 0
        INT_MIN = -1 * (2 ** 31)
        INT_MAX = (2 ** 31 - 1)
        sign = None
        if s[0] == '+':
            sign = 1
        elif s[0] == '-':
            sign = -1
        if sign:
            s = s[1:]
        if (not s) or (s[0] not in "0123456789"):
            return 0
        l = 0
        h = len(s)-1
        for c in range(len(s)):
            if s[c] not in "0123456789":
                h = c-1
                break
        s = s[l:h+1]
        n = int(float(s))
        if sign:
            n = n * sign
        if n < INT_MIN:
            return INT_MIN
        elif n > INT_MAX:
            return INT_MAX
        return n

#  if __name__ == '__main__':
#      print(Solution().myAtoi("    -42"))

