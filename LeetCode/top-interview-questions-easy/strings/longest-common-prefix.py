from functools import reduce
from typing import List

class Solution:

    #  def reducer(self, s1, s2):
    #      L = 0
    #      for x in range(min(len(s1), len(s2))):
    #          if s1[x] != s2[x]:
    #              break
    #          L += 1
    #      return s1[:L]

    #  def longestCommonPrefix(self, strs: List[str]) -> str:
    #      if not strs:
    #          return ""
    #      return reduce(self.reducer, strs)

    def longestCommonPrefix(self, strs:List[str]) -> str:
        prefix = ""
        if not strs:
            return prefix

        min_length = min([len(s) for s in strs])

        for i in range(min_length):
            if len(set(s[i] for s in strs)) == 1:
                prefix += strs[0][i]
            else:
                break
        return prefix


if __name__ == "__main__":
    print(Solution().longestCommonPrefix(["flower","flow","flight"]))
    print(Solution().longestCommonPrefix(["aa", "ab"]))
