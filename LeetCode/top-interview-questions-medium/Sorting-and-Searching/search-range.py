


class Solution:

    def searchRange(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        first = self._first(nums, target, 0, n-1)
        last = self._last(nums, target, 0, n-1)
        return [first, last]

    def _first(self, nums, K, l, h):
        n = len(nums)
        l, h = 0, n-1
        while l <= h:
            m = (l+h)//2
            if (m==0 or nums[m-1] < K) and nums[m]==K:
                return m
            elif K > nums[m]:
                l = m+1
            else:
                h = m-1
        return -1

    def _last(self, nums, K, l, h):
        n = len(nums)
        l, h = 0, n-1
        while l <= h:
            m = (l+h)//2
            if (m==n-1 or nums[m+1] > K) and nums[m]==K:
                return m
            elif nums[m] > K:
                h = m-1
            else:
                l = m+1
        return -1

