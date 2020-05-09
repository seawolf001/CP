



class Solution:
    def rob(self, nums: List[int]) -> int:
        if not nums:
            return 0
        n = len(nums)
        maxp = 0
        dp = [0] * n
        for x in range(n):
            inc = nums[x] + dp[x-2] if x-2 >=0 else nums[x]
            exc = dp[x-1]
            dp[x] = max(inc, exc)
            maxp = max(maxp, dp[x])
        return maxp
