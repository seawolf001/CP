from typing import List
from collections import defaultdict


class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        count=0
        n = len(nums)
        hashed = defaultdict(lambda: 0)
        curr = 0
        for x in nums:
            curr += x
            if curr == k:
                count += 1
            if curr - k in hashed:
                count += hashed[curr-k]
            hashed[curr] += 1
        return count

if __name__ == '__main__':
    s = Solution()
    assert s.subarraySum([10, 2, -2, -20, 10], -10) == 3
    assert s.subarraySum([9, 4, 20, 3, 10, 5], 33) == 2
    assert s.subarraySum([10, 2, -2, -20, 10], -10) == 3
