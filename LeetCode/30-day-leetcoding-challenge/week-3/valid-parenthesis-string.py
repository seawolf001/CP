

class Solution:
    def checkValidString(self, s: str) -> bool:
        if s is None: return True
        balanced = 0
        for c in s:
            if c == ')':
                balanced -= 1
            else:
                balanced += 1
            if balanced < 0:
                return False
        balanced = 0
        for c in reversed(s):
            if c == '(':
                balanced -= 1
            else:
                balanced += 1
            if balanced < 0:
                return False
        return True
