from collections import defaultdict

class Solution:
    ''''''
    def numJewelsInStones(self, J: str, S: str) -> int:
        f = defaultdict(lambda: 0)
        for c in S:
            f[c] += 1
        ans = 0
        for c in J:
            ans += f[c]
        return ans

