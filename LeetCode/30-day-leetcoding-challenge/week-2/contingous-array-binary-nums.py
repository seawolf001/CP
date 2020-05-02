from typing import List

class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        nums = [1 if x==1 else -1 for x in nums]
        mapped = dict()
        n = len(nums)
        curr = 0
        maxL = 0
        idx = 0
        for x in range(n):
            curr += nums[x]
            if curr == 0:
                maxL = max(maxL, (x+1))
                idx = x
            if curr in mapped:
                maxL = max(maxL, x - mapped[curr])
            else:
                mapped[curr] = x
        return maxL

#  print(Solution().findMaxLength([0,1,0,1,1,1,0,0]))
