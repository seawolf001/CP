#  from collections import Counter
import string

class Solution:
    def firstUniqChar(self, s: str) -> int:
        idx = float('inf')
        for c in string.ascii_lowercase:
            l = s.find(c)
            r = s.rfind(c)
            if l != -1 and l == r:
                idx = min(idx, l)
        return -1 if idx==float('inf') else idx
        #  counter = Counter(s)
        #  for x in range(len(s)):
        #      if counter[s[c]]==1:
        #          return x
        #  return -1
