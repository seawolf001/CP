
def char_to_int(c):
    return ord(c) - 64

class Solution:
    def titleToNumber(self, s: str) -> int:
        if not s:
            return 0
        s = s[::-1]
        ans = 0
        for n in range(len(s)):
            ans += char_to_int(s[n]) * 26**n
        return ans

assert Solution().titleToNumber("A")==1
assert Solution().titleToNumber("AB")==28
assert Solution().titleToNumber("ZY")==701
