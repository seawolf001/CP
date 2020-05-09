
# KADANE O(n)

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        best = float('-inf')
        curr = 0
        for x in nums:
            curr = max(x, curr+x)
            if curr > best:
                best = curr
        return best

