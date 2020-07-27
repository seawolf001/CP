from typing import List

class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        n = len(nums)
        for i in range(n):
            if not (0 < nums[i] <= n):
                continue
            pos = nums[i]-1
            while (1 <= nums[i] <= n) and (nums[i] != nums[pos]):
                nums[i], nums[pos] = nums[pos], nums[i]
                pos = nums[i]-1
        #  print(nums)
        for i in range(n):
            if i+1 != nums[i]:
                return i+1
        return n+1

#  Solution().firstMissingPositive([3,4,-1,1])
