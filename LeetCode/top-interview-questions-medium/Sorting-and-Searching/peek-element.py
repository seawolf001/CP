

class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        n = len(nums)
        return self._peek(nums, 0, n-1)

    def _peek(self, nums, l, h):
        m = (l + h) // 2
        if (m == 0 or nums[m] >= nums[m-1]) and (m == len(nums)-1 or nums[m] >= nums[m+1]):
            return m
        elif m > 0 and nums[m-1] > nums[m]:
            return self._peek(nums, l, m-1)
        else:
            return self._peek(nums, m+1, h)

