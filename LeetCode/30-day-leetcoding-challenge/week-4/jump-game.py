from typing import List

class Solution:
    def canJump(self, nums: List[int]) -> bool:
        pass

    def canJump_recurr(self, nums:List[int], l: int, h: int) -> bool:
        n = len(nums)
        if l > h or l > n or h > n:
            return False
        if l == h:
            return True
        if arr[l] <= 0:
            return False

        for x in range(l)
