from typing import List

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        if n==1: return 0
        prod = [1]*n
        p = 1
        for i in range(n):
            prod[i] = p
            p *= nums[i]
        p = 1
        for i in range(n-1, -1, -1):
            prod[i] *= p
            p *= nums[i]
        return prod
