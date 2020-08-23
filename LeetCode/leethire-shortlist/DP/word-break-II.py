
from typing import List

class Solution:
    """"""
    CACHE = dict()
    def __wordbreak_dp(self, s, n, wordDict):
        """"""
        res = []
        if n == 0:
            return [""]
        if n in Solution.CACHE:
            return Solution.CACHE.get(n)
        for x in range(n):
            sub = s[x:n]
            if sub in wordDict:
                _res = self.__wordbreak_dp(s, x, wordDict)
                for tmp in _res:
                    if not tmp:
                        res.append(sub)
                    else:
                        res.append(tmp + " " + sub)
        Solution.CACHE[n] = res
        return res

    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        """"""
        Solution.CACHE = {}
        return self.__wordbreak_dp(s, len(s), wordDict)

#  print(Solution().wordBreak("catsanddog", ["cat", "cats", "and", "sand", "dog"]))
