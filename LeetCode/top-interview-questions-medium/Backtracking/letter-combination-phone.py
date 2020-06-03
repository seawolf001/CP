
from collections import deque
from typing import List

class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        keys = [
            "", "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
        ]
        ans = []
        if len(digits)==0:
            return ans
        q = deque([""])
        while len(q)!=0:
            s = q.popleft()
            if len(s)==len(digits):
                ans.append(s)
            else:
                for char in keys[int(digits[len(s)])]:
                    q.append(s+char)
        return ans


