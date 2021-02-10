from collections import defaultdict

class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        f = defaultdict(lambda : 0)
        for c in magazine:
            f[c] += 1
        for c in ransomNote:
            f[c] -= 1
        for n in f.values():
            if n < 0:
                return False
        return True
